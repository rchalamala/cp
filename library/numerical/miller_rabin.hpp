#ifndef MILLER_RABIN__HPP
#define MILLER_RABIN__HPP

// Verification:
//

#include "../general/base.hpp"
#include "modular.hpp"
#include "trailing_zeros.hpp"
#include <cassert>
#include <cmath>
#include <cstdint>
#include <vector>

// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/MillerRabin.h
template<typename T> bool miller_rabin(const T& n, const std::vector<T>& A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
{
	if(n < 2 || n % 6 % 4 != 1) return n >= 2 && n - 2 < 2;
	MODULUS::value = n;
	T bits = trailing_zeros(n - 1), d = n >> bits;
	for(auto& a : A)
	{
		T x = static_cast<T>(VariableModulus(a) ^ d), i = bits;
		for(; x != 1 && x != n - 1 && a % n && i; x = static_cast<T>(VariableModulus(x) * x), --i);
		if(x != n - 1 && i != bits) return false;
	}
	return true;
}

#endif