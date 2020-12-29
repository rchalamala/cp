#ifndef GCD_HPP
#define GCD_HPP

#include "trailing_zeros.hpp"
#include <cstdint>
#include <tuple>
#include <utility>

// https://cp-algorithms.com/algebra/euclid-algorithm.html
template<typename T> T euclidian_gcd(const T& u_a, const T& u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	while(b) std::swap(a %= b, b);
	return a;
}

// https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
template<typename T> std::tuple<T, T, T> extended_euclidian_gcd(const T& u_a, const T& u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	std::pair<T, T> signs{a / u_a, b / u_b};
	T x = 1, y = 0, x1 = 0, y1 = 1;
	while(b)
	{
		T quotient = a / b;
		std::swap(x -= (quotient * x1), x1);
		std::swap(y -= (quotient * y1), y1);
		std::swap(a -= (quotient * b), b);
	}
	return std::make_tuple(x * signs.first, y * signs.second, a);
}

// https://cp-algorithms.com/algebra/euclid-algorithm.html
template<typename T> T binary_gcd(const T& u_a, const T u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	if(a == 0) return b;
	if(b == 0) return a;
	T shift = trailing_zeros(a | b);
	a >>= trailing_zeros(a);
	do
	{
		b >>= trailing_zeros(b);
		if(a > b) std::swap(a, b);
		b -= a;
	} while(b);
	return a << shift;
}

#endif