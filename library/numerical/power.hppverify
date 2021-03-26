#ifndef POWER_HPP
#define POWER_HPP

// Verification:
//

#include <type_traits>

template<typename T> T power(T base, T exponent)
{
	static_assert(std::is_integral_v<T>);
	assert(exponent >= 0);
	T result = 1;
	while(exponent)
	{
		if(exponent % 2)
		{
			result *= base;
		}
		base *= base;
		exponent /= 2;
	}
	return result;
}

#endif