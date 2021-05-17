#ifndef POLLARDS_RHO_FACTORIZATION_HPP
#define POLLARDS_RHO_FACTORIZATION_HPP

#include <algorithm>
#include <type_traits>
#include <vector>

#include "../../general/prng.hpp"
#include "../list_of_primes.hpp"
#include "../primality/miller_rabin_primality_test.hpp"
#include "../steins_gcd.hpp"

namespace factors
{
	template<typename T> T pollards_rho(const T& n)
	{
		static_assert(std::is_integral_v<T>);
		static_assert(std::is_unsigned_v<T>);
		assert(n >= 0);
		if((n & 1) ^ 1)
		{ return 2; }
		if(primality::miller_rabin(n))
		{ return n; }
		auto f{[&n](const T& x, const T& c) -> T
		       { return static_cast<T>((static_cast<unsigned __int128>(x) * x + c) % n);; }};
		for(T x0{getUID<T>(0, n - 1)};; x0 = getUID<T>(0, n - 1))
		{
			T c = getUID<T>(0, n - 1), x{f(x0, c)}, y{f(x, c)};
			while(true)
			{
				T divisor{steins_gcd(std::max(x, y) - std::min(x, y), n)};
				if(divisor == n)
				{ break; }
				if(divisor != 1)
				{ return divisor; }
				x = f(x, c);
				y = f(f(y, c), c);
			}
		}
	}

	template<typename T> std::vector<T> pollards_rho_factorize(T n, const bool& checkBaseCases = true)
	{
		static_assert(std::is_integral_v<T>);
		assert(n >= 0);
		if(n <= 1)
		{ return {}; }
		if(checkBaseCases)
		{
			T start{n};
			std::vector<T> original{};
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
			std::vector<T> divided{pollards_rho_factorize(start, false)};
			std::move(std::begin(divided), std::end(divided), std::back_inserter(original));
			return original;
		}
		T factor = pollards_rho<T>(n);
		if(n == factor)
		{ return std::vector<T>{n}; }
		n /= factor;
		std::vector<T> original{pollards_rho_factorize(factor, false)};
		std::size_t bound = original.size();
		for(std::size_t i{}; i < bound && n > 1; ++i)
		{
			while(n % original[i] == 0)
			{
				original.push_back(original[i]);
				n /= original[i];
			}
		}
		if(n > 1)
		{
			std::vector<T> divided{pollards_rho_factorize(n, false)};
			std::move(std::begin(divided), std::end(divided), std::back_inserter(original));
		}
		return original;
	}
}

#endif