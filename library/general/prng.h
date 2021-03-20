#ifndef PRNG_H
#define PRNG_H

#include <random>

inline std::mt19937_64& getPRNG();

template <typename T>
T getUID(const T& low, const T& high);

template <typename T>
T getURD(const T& low, const T& high);

#endif
