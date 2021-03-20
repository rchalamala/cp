#ifndef BI_EDGE_H
#define BI_EDGE_H

#include <cstddef>

struct BiEdge {
	static constexpr bool reversable = true;
	std::size_t to;

	explicit BiEdge(const std::size_t& u_to) : to{u_to} {};
};

#endif