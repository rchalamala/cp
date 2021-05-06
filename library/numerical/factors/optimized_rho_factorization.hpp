#ifndef OPTIMIZED_RHO_FACTORIZATION_HPP
#define OPTIMIZED_RHO_FACTORIZATION_HPP

#include <type_traits>
#include <vector>

#include "../../general/base.hpp"
#include "../../general/prng.hpp"
#include "../list_of_primes.hpp"
#include "../montgomery.hpp"
#include "../primality/miller_rabin_primality_test.hpp"
#include "../steins_gcd.hpp"
#include "../trailing_zero_bits.hpp"

namespace factors
{
	template<typename T> T optimized_rho(const T& n)
	{
		static_assert(std::is_integral_v < T > );
		assert(n >= 0);
		if(primality::miller_rabin(n, false))
		{ return n; }
		auto f{[&n](const Montgomery& x, const T& c) -> Montgomery
		       {
			       Montgomery result = x;
			       (result *= result);
			       result.n += c;
			       if(result.n >= n)
			       { result.n -= n; }
			       return result;
		       }};
		T factor, c{getUID < T > (0, n - 1)};
		Montgomery x{getUID < T > (0, n - 1)}, y{f(x, c)}, product{1};
		for(T trials{}; trials % 128 || (factor = steins_gcd(product.value(), n)) == 1; x = f(x, c), y = f(f(y, c), c))
		{
			if(x.n == y.n)
			{
				c = getUID < T > (0, n - 1);
				x = Montgomery(getUID < T > (0, n - 1));
				y = f(x, c);
			}
			Montgomery combined{product};
			combined *= Montgomery{std::max(x.n, y.n) - std::min(x.n, y.n)};
			if(combined.n && combined.n != product.n)
			{
				++trials;
				product = combined;
			}
		}
		return factor;
	}

	template<typename T> std::vector <T> optimized_rho_factorize(const T& n, const bool& checkBaseCases = true)
	{
		static_assert(std::is_integral_v < T > );
		assert(n >= 0);
		if(n <= 1)
		{ return {}; }
		if(checkBaseCases)
		{
			T start{n};
			std::vector <T> original{};
			for(const auto& a : largePrimes)
			{
				if(a > start)
				{ break; }
				while(start % a == 0)
				{
					original.push_back(a);
					start /= a;
				}
			}
			std::vector <T> divided{optimized_rho_factorize(start, false)};
			std::move(std::begin(divided), std::end(divided), std::back_inserter(original));
			return original;
		}
		T factor = optimized_rho<T>(n);
		if(n == factor)
		{ return std::vector < T > {n}; }
		std::vector <T> original{optimized_rho_factorize(factor, false)}, divided{optimized_rho_factorize(n / factor, false)};
		std::move(std::begin(divided), std::end(divided), std::back_inserter(original));
		return original;
	}
}

#endif