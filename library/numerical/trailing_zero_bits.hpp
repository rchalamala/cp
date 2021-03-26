#ifndef TRAILING_ZERO_BITS_HPP
#define TRAILING_ZERO_BITS_HPP

// Verification:
//

#include <type_traits>

template<typename T> T trailing_zero_bits(T element)
{
	static_assert(std::is_integral_v<T>);
	T result = 0;
	for(; (element & 1) ^ 1; ++result)
	{
		element >>= 1;
	}
	return result;
}

#endif