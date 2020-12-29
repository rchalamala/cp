#ifndef CHOOSE_HPP
#define CHOOSE_HPP

#include "../general/base.hpp"
#include "modular.hpp"
#include <cstdint>

std::uint64_t choose(const std::uint64_t& n, const std::uint64_t& k) { return k ? n * choose(n - 1, k - 1) / k : 1; }

std::uint64_t choose(const std::uint64_t& n, const std::uint64_t& k, const std::uint64_t& modulus)
{
	if(!k) return 1;
	std::uint64_t result = choose(n - 1, k - 1);
	MODULUS::value = modulus;
	return static_cast<std::uint64_t>(VariableModulus(n) * result);
}

#endif