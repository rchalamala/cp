#ifndef PRNG_HPP
#define PRNG_HPP

#include <chrono>
#include <type_traits>
#include <random>

inline std::mt19937_64& getPRNG()
{
	#ifdef LOCAL
	static std::mt19937_64 PRNG{0};
	#else
	static std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};
	#endif
	return PRNG;
}

template<typename T1, typename T2> typename std::common_type<T1, T2>::type getUID(const T1& uLow, const T2& uHigh)
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	typename std::common_type<T1, T2>::type low{uLow}, high{uHigh};
	return std::uniform_int_distribution<typename std::common_type<T1, T2>::type>(low, high)(getPRNG());
}

template<typename T1, typename T2> typename std::common_type<T1, T2>::type getURD(const T1& uLow, const T2& uHigh)
{
	static_assert(std::is_floating_point_v<T1>);
	static_assert(std::is_floating_point_v<T2>);
	typename std::common_type<T1, T2>::type low{uLow}, high{uHigh};
	return std::uniform_real_distribution<typename std::common_type<T1, T2>::type>(low, high)(getPRNG());
}

#endif