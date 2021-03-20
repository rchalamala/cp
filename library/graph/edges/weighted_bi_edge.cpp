// Verification:
//

#include "weighted_bi_edge.h"

template <typename T>
WeightedBiEdge<T>::WeightedBiEdge(const std::size_t& u_to, const T& u_weight)
    : BiEdge{u_to}, weight{u_weight} {
}