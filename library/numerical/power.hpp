#ifndef POWER_HPP
#define POWER_HPP

template<typename T> T power(T base, T exponent)
{
	T result = 1;
	while(exponent)
	{
		if(exponent % 2) result *= base;
		base *= base;
		exponent /= 2;
	}
	return result;
}

#endif