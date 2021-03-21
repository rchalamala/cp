#ifndef POLLARDS_RHO_FACTORIZATION_HPP
#define POLLARDS_RHO_FACTORIZATION_HPP

// Verification:
//

#include <cmath>
#include <type_traits>
#include <vector>

#include "../primality/prime.hpp"

template<typename T> T pollards_rho(const T& n, const T& c = 1)
{
	static_assert(std::is_integral_v<T>);
	assert(n >= 0);
	if(prime(n)) return n;
	auto f = [&n, &c](const T& x) -> T { return (((x % n) * (x % n)) % n + c) % n; };
	T x = 2, y = f(f(x));
	while(x != y)
	{
		T divisor = gcd(abs(x - y), n);
		if(divisor == n)
		{
			return pollards_rho(n, c + 1);
		}
		if(divisor != 1)
		{
			return divisor;
		}
		x = f(x);
		y = f(f(y));
	}
	return pollards_rho(n, c + 1);
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