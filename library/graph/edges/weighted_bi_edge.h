#ifndef WEIGHTED_BI_EDGE_H
#define WEIGHTED_BI_EDGE_H

#include "bi_edge.h"

template <typename T>
struct WeightedBiEdge : BiEdge {
  static constexpr bool reversable = true;
  T weight;

  explicit WeightedBiEdge(const std::size_t& u_to, const T& u_weight);
};

#endif