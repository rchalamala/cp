#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

#include "miller_rabin.hpp"
#include "pollards_rho.hpp"
#include <cmath>
#include <cstdint>
#include <type_traits>
#include <vector>

// https://github.com/yosupo06/library-checker-problems/blob/master/math/factorize/sol/correct.cpp
template<typename T> std::vector<T> factorize(const T& n)
{
	if(n == 1) return std::vector<T>();
	T factor = pollards_rho<T>(n);
	if(n == factor) return std::vector<T>{n};
	std::vector<T> original{factorize(factor)}, divided{factorize(n / factor)};
	original.insert(original.end(), divided.begin(), divided.end());
	return original;
}

#endif