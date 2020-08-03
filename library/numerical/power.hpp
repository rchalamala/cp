#ifndef POWER_HPP
#define POWER_HPP

// Verification:
//

#include <cstddef>

template<typename T, std::size_t modulus> T power(T base, T exponent)
{
	if(exponent < 0) return base == 1 ? 1 : 0;
	if(modulus) base %= modulus;
	T result = 1;
	while(exponent)
	{
		if(exponent % 2)
		{
			result *= base;
			if(modulus) result %= modulus;
		}
		base *= base;
		if(modulus) base %= modulus;
		exponent /= 2;
	}
	return modulus ? result % modulus : result;
}

#endif