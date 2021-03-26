#ifndef OPTIMIZED_RHO_FACTORIZATION_HPP
#define OPTIMIZED_RHO_FACTORIZATION_HPP

#include <chrono>
#include <cmath>
#include <type_traits>
#include <vector>
#include <random>

#include "../../general/base.hpp"
#include "../../general/prng.hpp"
#include "../steins_gcd.hpp"
#include "../primality/miller_rabin_primality_test.hpp"
#include "../trailing_zero_bits.hpp"

namespace factors
{
	template<typename T> T optimized_rho(const T& n)
	{
		static_assert(std::is_integral_v<T>);
		assert(n >= 0);
		if(primality::miller_rabin(n, true))
		{ return n; }
		T c;
		auto f = [&n, &c](const T& x) -> T
		{ return (static_cast<uli>(x) * x + c) % n; };
		for(T x0 = getUID<T>(static_cast<T>(0), n - 1);; x0 = getUID<T>(static_cast<T>(0), n - 1))
		{
			c = getUID<T>(static_cast<T>(0), n - 1);
			T product = 1;
			for(T x = f(x0), y = f(x), trials = 30; x != y && (trials % 40 || steins_gcd(product, n) == 1); x = f(x), y = f(f(y)))
			{
				T combined = static_cast<uli>(product) * (n + x - y) % n;
				if(combined)
				{ ++trials, product = combined; }
			}
			T factor = steins_gcd(product, n);
			if(factor != 1 && factor != n)
			{ return factor; }
		}
	}

	template<typename T> std::vector<T> optimized_rho_factorize(const T& n, const bool& checkBaseCases = true)
	{
		static_assert(std::is_integral_v<T>);
		assert(n >= 0);
		if(n <= 1)
		{ return {}; }
		if(checkBaseCases)
		{
			T start = n;
			std::vector<T> original{};
			for(const auto& a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 })
			{
				if(a > start)
				{ break; }
				while(start % a == 0)
				{
					original.push_back(a);
					start /= a;
				}
			}
			std::vector<T> divided{ optimized_rho_factorize(start, false) };
			original.insert(original.end(), divided.begin(), divided.end());
			return original;
		}
		T factor = optimized_rho<T>(n);
		if(n == factor)
		{ return std::vector<T>{ n }; }
		std::vector<T> original{ optimized_rho_factorize(factor, false) }, divided{ optimized_rho_factorize(n / factor, false) };
		original.insert(original.end(), divided.begin(), divided.end());
		return original;
	}
}

#endif