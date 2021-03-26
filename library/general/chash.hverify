#ifndef CHASH_H
#define CHASH_H

#include <cstdint>
#include <utility>

struct chash {
  static std::uint64_t splitmix64(std::uint64_t x);

  std::uint64_t operator()(const std::uint64_t x) const;

  std::uint64_t operator()(
      const std::pair<std::uint64_t, std::uint64_t> x) const;
};

#endif