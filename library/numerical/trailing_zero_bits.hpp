#ifndef TRAILING_ZERO_BITS_HPP
#define TRAILING_ZERO_BITS_HPP

#include <cstdint>
#include <type_traits>

template<typename T> std::uint64_t trailing_zero_bits(const T& element)
{
	static_assert(std::is_integral_v<T>);
	return __builtin_ctzll(element);
}

/*
template<typename T> T trailing_zero_bits(T element)
{
	static_assert(std::is_integral_v<T>);
	T result{};
	for(; (element & 1) ^ 1; ++result)
	{
		element >>= 1;
	}
	return result;
}
*/

#endif