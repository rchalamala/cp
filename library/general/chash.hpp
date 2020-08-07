#ifndef CHASH_HPP
#define CHASH_HPP

// Verification:
//

#include <cstddef>
#include <cstdint>
#include <chrono>
#include <utility>

// https://codeforces.com/blog/entry/62393
struct chash
{
	// http://xorshift.di.unimi.it/splitmix64.c
	static std::uint64_t inline splitmix64(std::uint64_t x)
	{
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30ULL)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27ULL)) * 0x94d049bb133111eb;
		return x ^ (x >> 31ULL);
	}

	std::size_t inline operator()(std::uint64_t x) const
	{
		static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
		return splitmix64(x + FIXED_RANDOM);
	}

	std::size_t inline operator()(std::pair<std::uint64_t, std::uint64_t> x) const
	{
		static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());
		return splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM) >> 1ULL);
	}
};

#endif