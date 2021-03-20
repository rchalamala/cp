#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include "edge.h"

template <typename T>
struct WeightedEdge : Edge {
  static constexpr bool reversable = true;
  T weight;

  explicit WeightedEdge(const std::size_t& u_to, const T& u_weight);
};

#endif