#ifndef POLLARDS_RHO_FACTORIZATION_HPP
#define POLLARDS_RHO_FACTORIZATION_HPP

#include <algorithm>
#include <type_traits>
#include <vector>

#include "../../general/base.hpp"
#include "../../general/prng.hpp"
#include "../primality/miller_rabin_primality_test.hpp"
#include "../steins_gcd.hpp"

namespace factors
{
	template<typename T> T pollards_rho(const T& n)
	{
		static_assert(std::is_integral_v<T>);
		assert(n >= 0);
		if((n & 1) ^ 1)
		{ return 2; }
		if(primality::miller_rabin(n))
		{ return n; }
		T c;
		auto f = [&n, &c](const T& x) -> T
		{ return (static_cast<uli>(x) * x + c) % n; };
		for(T x0 = getUID<T>(static_cast<T>(0), n - 1);; x0 = getUID<T>(static_cast<T>(0), n - 1))
		{
			c = getUID<T>(static_cast<T>(0), n - 1);
			T x = f(x0), y = f(x);
			while(true)
			{
				T divisor = steins_gcd(std::max(x, y) - std::min(x, y), n);
				if(divisor == n)
				{ break; }
				if(divisor != 1)
				{ return divisor; }
				x = f(x);
				y = f(f(y));
			}
		}
	}

	template<typename T> std::vector<T> pollards_rho_factorize(const T& n)
	{
		static_assert(std::is_integral_v<T>);
		assert(n >= 0);
		if(n <= 1)
		{ return {}; }
		T factor = pollards_rho<T>(n);
		if(n == factor)
		{ return std::vector<T>{ n }; }
		std::vector<T> original{ pollards_rho_factorize(factor) }, divided{ pollards_rho_factorize(n / factor) };
		original.insert(original.end(), divided.begin(), divided.end());
		return original;
	}
}

#endif