#ifndef WEIGHTED_BI_EDGE_HPP
#define WEIGHTED_BI_EDGE_HPP

// Verification:
//

#include "../graph.hpp"
#include "bi_edge.hpp"
#include <cstddef>

template<typename T> struct WeightedBiEdge : public BiEdge
{
	static constexpr bool reversable = true;
	T weight;

	WeightedBiEdge(const std::size_t& u_to, const T& u_weight) : BiEdge{u_to}, weight{u_weight} {}
};

#endif

