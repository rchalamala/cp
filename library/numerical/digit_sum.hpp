#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

// Verification:
//

#include <cassert>
#include <type_traits>

template<typename T1, typename T2> T1 digit_sum(T1 n, const T2& base = 10)
{
	static_assert(std::is_integral_v<T1>);
	static_assert(std::is_integral_v<T2>);
	assert(n >= 0);
	T1 result = 0;
	while(n)
	{
		result += n % base;
		n /= base;
	}
	return result;
}

#endif