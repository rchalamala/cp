// http://xorshift.di.unimi.it/splitmix64.c
// Verification:
//

#include "chash.h"

#include <chrono>
#include <cstdint>
#include <utility>

std::uint64_t chash::splitmix64(std::uint64_t x) {
  x += 0x9e3779b97f4a7c15;
  (x ^= x >> 30ULL) *= 0xbf58476d1ce4e5b9;
  (x ^= x >> 27ULL) *= 0x94d049bb133111eb;
  return x ^ x >> 31ULL;
}

std::uint64_t chash::operator()(const std::uint64_t x) const {
  static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(
      std::chrono::steady_clock::now().time_since_epoch().count());
  return splitmix64(x + FIXED_RANDOM);
}

std::uint64_t chash::operator()(
    const std::pair<std::uint64_t, std::uint64_t> x) const {
  static const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(
      std::chrono::steady_clock::now().time_since_epoch().count());
  return splitmix64(x.first + FIXED_RANDOM) ^
         (splitmix64(x.second + FIXED_RANDOM) >> 1ULL);
}