#ifndef PRNG_HPP
#define PRNG_HPP

#include <chrono>
#include <type_traits>
#include <random>

inline std::mt19937_64& getPRNG()
{
	static std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};
	return PRNG;
}

template<typename T1, typename T2> typename std::common_type<T1, T2>::type getUID(const T1& u_low, const T2& u_high)
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	typename std::common_type<T1, T2>::type low{u_low}, high{u_high};
	return std::uniform_int_distribution<typename std::common_type<T1, T2>::type>(low, high)(getPRNG());
}

template<typename T1, typename T2> typename std::common_type<T1, T2>::type getURD(const T1& u_low, const T2& u_high)
{
	static_assert(std::is_floating_point_v<T1>);
	static_assert(std::is_floating_point_v<T2>);
	typename std::common_type<T1, T2>::type low{u_low}, high{u_high};
	return std::uniform_real_distribution<typename std::common_type<T1, T2>::type>(low, high)(getPRNG());
}

#endif