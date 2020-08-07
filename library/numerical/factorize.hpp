#ifndef FACTORIZE_HPP
#define FACTORIZE_HPP

#include "miller_rabin.hpp"
#include "pollards_rho.hpp"
#include <cstdint>
#include <vector>

std::vector<std::uint64_t> factorize(const std::uint64_t& n)
{
	if(n == 1) return std::vector<std::uint64_t>();
	std::uint64_t factor = pollards_rho(n);
	if(n == factor) return std::vector<std::uint64_t>{n};
	std::vector<std::uint64_t> original{factorize(factor)}, divided{factorize(n / factor)};
	original.insert(original.end(), divided.begin(), divided.end());
	return original;
}

#endif