#ifndef TRAILING_ZEROS
#define TRAILING_ZEROS

// Verification:
//

#include <cstdint>
#include <type_traits>

template<typename T> T trailing_zeros(const T& u_element)
{
	#ifdef __GNUG__
	return __builtin_ctzll(u_element);
	#else
	T result = 0;
	std::is_unsigned<T>::value ? for(T element = u_element; !(element & 1); element >>= 1, ++result) : for(T element = u_element; element % 2 == 0; element /= 2, ++result);
	return result;
	#endif
}

#endif