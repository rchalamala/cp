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
	std::int_fast16_t q;
	read(std::cin, q);
	while(q--)
	{
		std::int_fast64_t a;
		read(std::cin, a);
		std::vector<std::int_fast64_t> factors = factors::pollards_rho_factorize<std::int_fast64_t>(a);
		std::sort(std::begin(factors), std::end(factors));
		prints(std::cout, std::size(factors), factors);
	}
	std::fflush(stdout);
}
