#ifndef WEIGHTED_EDGE_HPP
#define WEIGHTED_EDGE_HPP

#include "../graph.hpp"
#include "edge.hpp"
#include <cstddef>

template<typename T>
struct WeightedEdge : public Edge
{
	static constexpr bool reversable = false;
	T weight;
	WeightedEdge(const std::size_t& u_to, const T& u_weight)
			:Edge{ u_to }, weight{ u_weight }
	{
	}
};

#endif