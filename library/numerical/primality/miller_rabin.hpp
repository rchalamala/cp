#ifndef MILLER_RABIN_HPP
#define MILLER_RABIN_HPP

// https://github.com/kth-competitive-programming/kactl/blob/master/content/number-theory/MillerRabin.h
// Verification:
//

#include <type_traits>
#include <vector>

#include "../trailing_zero_bits.hpp"

template <typename T>
bool miller_rabin(const T& n,
                  const std::vector<T>& A = {2, 325, 9375, 28178, 450775,
                                             9780504, 1795265022}) {
  static_assert(std::is_integral<T>::value);
  static_assert(std::is_signed<T>::value);
  if (n < 2 || n % 6 % 4 != 1) return n >= 2 && n - 2 < 2;
  MODULUS::value = n;
  T bits = trailing_zero_bits(n - 1), d = n >> bits;
  for (auto&& a : A) {
    T x = static_cast<T>(VariableModulus(a) ^ d), i = bits;
    for (; x != 1 && x != n - 1 && a % n && i; --i)
      x = static_cast<T>(VariableModulus(x) * x);
    if (x != n - 1 && i != bits) return false;
  }
  return true;
}

#endif