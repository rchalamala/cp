#ifndef MILLER_RABIN_PRIMALITY_TEST_HPP
#define MILLER_RABIN_PRIMALITY_TEST_HPP

#include <limits>
#include <type_traits>
#include <vector>

#include "../../general/base.hpp"
#include "../list_of_primes.hpp"
#include "../montgomery.hpp"
#include "../trailing_zero_bits.hpp"

namespace primality
{

	template<typename T> Montgomery power(const Montgomery& base, T exponent)
	{
		static_assert(std::is_integral_v<T>);
		static_assert(std::is_unsigned_v<T>);
		Montgomery mBase = base, result(1);
		while(exponent)
		{
			if(exponent & 1)
			{ result *= mBase; }
			mBase *= mBase;
			exponent >>= 1;
		}
		return result;
	}

	template<typename T, std::size_t BasesSize = 7> bool miller_rabin(const T& n, const bool& checkBaseCases = true, const std::array<T, BasesSize>& A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
	{
		static_assert(std::is_integral_v<T>);
		static_assert(std::is_unsigned_v<T>);
		if(checkBaseCases)
		{
			if(n <= 1)
			{ return false; }
			for(const auto& a : largePrimes)
			{
				if(a > n)
				{ break; }
				if(n == a)
				{
					return true;
				}
				if(n % a == 0)
				{ return false; }
			}
		}
		if(Montgomery::modulus != n)
		{ Montgomery::set_modulus(n); }
		T bits{trailing_zero_bits(n - 1)}, d{(n - 1) >> bits};
		Montgomery one{1}, negativeOne{n - 1};
		for(const T& a : A)
		{
			Montgomery mA{a};
			if(mA.n)
			{
				T i{};
				Montgomery x{power(mA, d)};
				if(x.n == one.n || x.n == negativeOne.n)
				{ continue; }
				for(; x.n != one.n && x.n != negativeOne.n && i < bits; ++i)
				{
					if(x.n == one.n)
					{ return false; }
					if(x.n == negativeOne.n)
					{ break; }
					x *= x;
				}
				if((i == bits) ^ (x.n == one.n))
				{ return false; }
			}
			else
			{ return true; }
		}
		return true;
	}
}

#endif