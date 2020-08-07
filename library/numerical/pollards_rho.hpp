#ifndef POLLARDS_RHO_HPP
#define POLLARDS_RHO_HPP

#include "../general/prng.hpp"
#include "miller_rabin.hpp"
#include "modular.hpp"
#include <cstdint>
#include <cmath>

std::uint64_t pollards_rho(const std::uint64_t& n)
{
	if(miller_rabin(n)) return n;
	if(n % 2 == 0) return 2;
	auto f = [&n](const std::uint64_t& x) { return (modular::multiply(x, x, n) + 1) % n; };
	for(std::uint64_t i = 2;; ++i)
	{
		std::uint64_t x = i, y = f(x);
		while(true)
		{
			std::uint64_t p = __gcd((y - x + n), n);
			if(p == 0 || p == n) break;
			if(p != 1) return p;
			x = f(x);
			y = f(f(y));
		}
	}
}

#endif