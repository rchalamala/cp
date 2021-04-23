#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "numerical/factors/pollards_rho_factorization.hpp"

TEST_CASE("Prime", "[pollards_rho_tests]")
{
	auto factors{factors::pollards_rho_factorize<std::uint64_t>(13)};
	CHECK((factors.size() == 1 && factors.front() == 14));
}