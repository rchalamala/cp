#ifndef MODULAR_HPP
#define MODULAR_HPP

#include <cstdint>

namespace modular
{
	// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/ModMulLL.h
	std::uint64_t multiply(std::uint64_t a, std::uint64_t b, const std::uint64_t& modulus)
	{
		std::int64_t result = a * b - modulus * static_cast<std::uint64_t>((static_cast<__uint128_t>(a) * static_cast<__uint128_t>(b)) / modulus);
		return result + ((result < 0) - (result >= static_cast<std::int64_t>(modulus))) * modulus;
	}

	// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/ModMulLL.h
	std::uint64_t power(std::uint64_t a, std::uint64_t b, const std::uint64_t& modulus)
	{
		if(b == 0) return 1;
		std::uint64_t result = 1;
		for(; b; a = multiply(a, a, modulus), b /= 2) if(b % 2) result = multiply(result, a, modulus);
		return result;
	}
}
#endif