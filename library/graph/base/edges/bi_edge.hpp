#ifndef BI_EDGE_HPP
#define BI_EDGE_HPP

#include "../graph.hpp"
#include <cstddef>

struct BiEdge
{
	static constexpr bool reversable = true;
	std::size_t to;
public:
	BiEdge(const std::size_t& u_to)
			:to{ u_to }
	{
	}
};

#endif