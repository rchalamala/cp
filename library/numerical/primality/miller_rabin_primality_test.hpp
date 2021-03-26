#ifndef MILLER_RABIN_PRIMALITY_TEST_HPP
#define MILLER_RABIN_PRIMALITY_TEST_HPP

#include <type_traits>
#include <vector>

#include "../../general/base.hpp"
#include "../trailing_zero_bits.hpp"

namespace primality
{
	template<typename T> T power(T base, T exponent, const T& modulus)
	{
		base %= modulus;
		T result = 1;
		while(exponent)
		{
			if(exponent & 1)
			{
				result = static_cast<uli>(result) * base % modulus;
			}
			base = static_cast<uli>(base) * base % modulus;
			exponent >>= 1;
		}
		return result;
	}

	template<typename T> bool miller_rabin(const T& n, const bool& checkBaseCases = true, const std::vector<T>& A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022})
	{
		static_assert(std::is_integral_v<T>);
		if(checkBaseCases)
		{
			if(n <= 1)
			{ return false; }
			if(n <= 2)
			{ return true; }
			for(const auto& a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97})
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
		T bits = trailing_zero_bits(n - 1), d = (n - 1) >> bits, negativeOne = n - 1;
		for(const T& a : A)
		{
			if(a % n)
			{
				T x = power(a, d, n), i = 0;
				if(x == 1 || x == negativeOne)
				{ continue; }
				for(; x != 1 && x != negativeOne && i < bits; ++i)
				{
					if(x == 1)
					{ return false; }
					if(x == negativeOne)
					{ break; }
					x = static_cast<uli>(x) * x % n;
				}
				if((i == bits) ^ (x == 1))
				{ return false; }
			}
		}
		return true;
	}

}

#endif