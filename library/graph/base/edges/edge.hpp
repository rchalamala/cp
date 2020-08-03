#ifndef EDGE_HPP
#define EDGE_HPP

// Verification:
//

#include "../graph.hpp"
#include <cstddef>

struct Edge
{
	static constexpr bool reversable = false;
	std::size_t to;
public:
	Edge(const std::size_t& u_to) : to{u_to} {}
};

#endif