#ifndef CHASH_HPP
#define CHASH_HPP

// http://xorshift.di.unimi.it/splitmix64.c

#include <chrono>
#include <cstddef>
#include <cstdint>
#include <utility>

struct chash
{
	static std::uint64_t splitmix64(std::uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		(x ^= (x >> static_cast<std::uint64_t>(30))) *= 0xbf58476d1ce4e5b9;
		(x ^= (x >> static_cast<std::uint64_t>(27))) *= 0x94d049bb133111eb;
		return x ^ (x >> static_cast<std::uint64_t>(31));
	}

	std::size_t operator()(const std::uint64_t x) const
	{
		static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
		return splitmix64(x + FIXED_RANDOM);
	}

	std::size_t operator()(const std::pair <std::uint64_t, std::uint64_t> x) const
	{
		static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
		return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> static_cast<std::uint64_t>(1));
	}
};

#endif