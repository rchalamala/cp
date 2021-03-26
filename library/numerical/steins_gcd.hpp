#ifndef STEINS_GCD_HPP
#define STEINS_GCD_HPP

#include <algorithm>
#include <type_traits>
#include <utility>
#include "trailing_zero_bits.hpp"

template<typename T1, typename T2> constexpr typename std::common_type<T1, T2>::type steins_gcd(const T1& u_x, const T2& u_y)
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	typename std::common_type<T1, T2>::type x{u_x}, y{u_y};
	if(x == 0)
	{
		return y;
	}
	if(y == 0)
	{
		return x;
	}
	typename std::common_type<T1, T2>::type a{trailing_zero_bits(x)}, b{trailing_zero_bits(y)};
	x >>= a;
	y >>= b;
	while(true)
	{
		if(x < y)
		{
			std::swap(x, y);
		}
		x -= y;
		if(!x)
		{
			return y << std::min(a, b);
		}
		x >>= trailing_zero_bits(x);
	}
}

#endif