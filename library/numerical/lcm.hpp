#ifndef LCM_HPP
#define LCM_HPP

// Verification:
//

#include "gcd.hpp"
#include <cmath>
#include <cstdint>

// https://cp-algorithms.com/algebra/euclid-algorithm.html
template<typename T> T lcm(const T& u_a, const T& u_b)
{
	T a = std::abs(u_a), b = std::abs(u_b);
	return a / binary_gcd(a, b) * b;
}

#endif