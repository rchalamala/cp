#ifndef POLLARDS_RHO_FACTORIZATION_HPP
#define POLLARDS_RHO_FACTORIZATION_HPP

// Verification:
//

#include <cmath>
#include <type_traits>
#include <vector>

#include "../primality/prime.hpp"

template<typename T> T pollards_rho(const T& n)
{
	static_assert(std::is_integral_v<T>);
	assert(n >= 0);
	if(prime(n)) return n;
	for(std::size_t i = 2; i * i <= n; ++i)
	{
		if(n % i == 0)
		{
			return i;
		}
	}
}

template<typename T> std::vector<T> pollards_rho_factorize(const T& n)
{
	static_assert(std::is_integral_v<T>);
	assert(n >= 0);
	if(n <= 1) return {};
	T factor = pollards_rho<T>(n);
	if(n == factor) return std::vector<T>{n};
	std::vector<T> original{pollards_rho_factorize(factor)}, divided{pollards_rho_factorize(n / factor)};
	original.insert(original.end(), divided.begin(), divided.end());
	return original;
}

#endif