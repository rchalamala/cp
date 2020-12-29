#ifndef DIGIT_SUM_HPP
#define DIGIT_SUM_HPP

template<typename T> T digit_sum(T n)
{
	T result = 0;
	for(; n; result += n % 10, n /= 10);
	return result;
}

#endif