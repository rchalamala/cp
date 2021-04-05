#include "../../../library/general/input.hpp"
#include "../../../library/general/output.hpp"
#include "../../../library/general/speed.hpp"

#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

#include "../../../library/numerical/factors/pollards_rho_factorization.hpp"

int main()
{
	speed();
	std::int16_t q;
	read(std::cin, q);
	while(q--)
	{
		std::uint64_t a;
		read(std::cin, a);
		std::vector<std::uint64_t> factors = factors::pollards_rho_factorize<std::uint64_t>(a);
		std::sort(std::begin(factors), std::end(factors));
		std::cout << std::size(factors);
		for(const auto& factor : factors)
		{ std::cout << ' ' << factor; }
		std::cout << '\n';
	}
}
