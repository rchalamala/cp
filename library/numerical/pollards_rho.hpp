#ifndef POLLARDS_RHO_HPP
#define POLLARDS_RHO_HPP

// Verification:
//

#include "../general/base.hpp"
#include "../general/prng.hpp"
#include "gcd.hpp"
#include "miller_rabin.hpp"
#include "modular.hpp"
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <cmath>
#include <type_traits>

template<typename T> T pollards_rho(const T& n, const bool& already_passed = false)
{
	if(n % 2 == 0) return 2;
	if(!already_passed && miller_rabin<T>(n)) return n;
	MODULUS::value = n;
	T c = getUID<T>(1, n - 1);
	auto f = [&n, &c](const T& x) -> T { return static_cast<T>((VariableModulus(x) ^ 2) + c); };
	T x = getUID<T>(0, n - 1), y = f(x), divisor = 1;
	while(divisor == 1)
	{
		x = f(x);
		y = f(f(y));
		divisor = binary_gcd(x - y, n);
		if(divisor == n || x == y) return pollards_rho(n, false);
	}
	return divisor;
}

#endif