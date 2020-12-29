#ifndef LINEAR_DIOPHANTINE_HPP
#define LINEAR_DIOPHANTINE_HPP

#include "gcd.hpp"
#include <functional>
#include <tuple>
#include <utility>

template<typename T> class linear_diophantine
{
	std::tuple<T, T, T> gcd;
	T a, b;
public:
	linear_diophantine(const T& u_a, const T& u_b, const T& c) : a{u_a}, b{u_b}
	{
		gcd = extended_euclidian_gcd(a, b);
		assert(c % std::get<2>(gcd) == 0);
		std::get<0>(gcd) *= (c / std::get<2>(gcd));
		std::get<1>(gcd) *= (c / std::get<2>(gcd));
	}

	std::pair<T, T> shift(const T& m) { return std::make_pair(std::get<0>(gcd) + b * m, std::get<1>(gcd) - a * m); }

	std::pair<T, T> differences() { return std::make_pair(a, b); }
};

#endif