#ifndef TRAILING_ZERO_BITS_HPP
#define TRAILING_ZERO_BITS_HPP

// Verification:
//

#include <type_traits>

template<typename T> T trailing_zero_bits(T element)
{
	static_assert(std::is_integral_v<T>);
	static_assert(!std::is_same_v<std::remove_cv_t<T>, bool>);
	T result = 0;
	if(std::is_unsigned_v<T>)
	{
		for(; element ^ 1; ++result)
		{
			element >>= 1;
		}
	}
	else
	{
		for(; element % 2 == 0; ++result)
		{
			element /= 2;
		}
	}
	return result;
}

#endif