#ifndef PRNG_H
#define PRNG_H

#include <chrono>
#include <random>

inline std::mt19937_64& getPRNG()
{
	static std::mt19937_64 PRNG{ static_cast<std::uint_fast64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()) };
	return PRNG;
}

template<typename T> T getUID(const T& low, const T& high)
{
	return std::uniform_int_distribution<T>(low, high)(getPRNG());
}

template<typename T> T getURD(const T& low, const T& high)
{
	return std::uniform_real_distribution<T>(low, high)(getPRNG());
}

#endif