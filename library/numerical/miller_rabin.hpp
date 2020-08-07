#ifndef MILLER_RABIN__HPP
#define MILLER_RABIN__HPP

#include "modular.hpp"
#include <cstdint>
#include <vector>

// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/MillerRabin.h
bool miller_rabin(const std::uint64_t& n)
{
	if(n < 2 || n % 6 % 4 != 1) return n - 2 < 2;
	std::vector<std::uint64_t> A{2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	std::uint64_t bits = __builtin_ctzll(n - 1), d = n >> bits;
	for(auto& a : A)
	{
		std::uint64_t x = modular::power(a, d, n), i = bits;
		while(x != 1 && x != n - 1 && a % n && i--) x = modular::multiply(x, x, n);
		if(x != n - 1 && i != bits) return false;
	}
	return true;
}

#endif