#ifndef PRNG_HPP
#define PRNG_HPP

#include <chrono>
#include <type_traits>
#include <random>

inline std::mt19937_64& get_rng()
{
	#ifdef LOCAL
	static std::mt19937_64 rng{};
	#else
	static std::mt19937_64 rng{static_cast<std::uint64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};
	#endif
	return rng;
}

template<typename T1, typename T2> typename std::common_type_t<T1, T2> getUID(const T1& uLow, const T2& uHigh, std::mt19937_64& device = get_rng())
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	typename std::common_type_t<T1, T2> low{uLow}, high{uHigh};
	return std::uniform_int_distribution<typename std::common_type<T1, T2>::type>(low, high)(device);
}

template<typename T1, typename T2> typename std::common_type_t<T1, T2> getURD(const T1& uLow, const T2& uHigh, std::mt19937_64& device = get_rng())
{
	static_assert(std::is_floating_point_v<T1>);
	static_assert(std::is_floating_point_v<T2>);
	typename std::common_type_t<T1, T2> low{uLow}, high{uHigh};
	return std::uniform_real_distribution<typename std::common_type<T1, T2>::type>(low, high)(device);
}

#endif