#ifndef STEINS_GCD_HPP
#define STEINS_GCD_HPP

// https://cp-algorithms.com/algebra/euclid-algorithm.html
// Verification:
//

#include <type_traits>
#include <utility>
#include "trailing_zero_bits.hpp"

template<typename T1, typename T2> std::common_type<T1, T2> binary_gcd(T1 a, T2 b)
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	if(a == 0)
	{
		return b;
	}
	if(b == 0)
	{
		return a;
	}
}

#endif