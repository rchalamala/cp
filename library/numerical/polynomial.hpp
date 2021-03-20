#ifndef POLYNOMIAL_HPP
#define POLYNOMIAL_HPP

// Verification:
//

#include <cmath>
#include <cstddef>
#include <vector>

template <typename T,
          typename = std::enable_if<std::is_integral<
              typename std::decay<decltype(T::value)>::type>::value>>
class Polynomial {
  std::vector<T> polynomial{};

  void trim() {
    while (!polynomial.empty() && polynomial.back() == T(0))
      polynomial.pop_back();
  }

 public:
  Polynomial(const std::vector<T>& coefficients) : polynomial{coefficients} {
    trim();
  }

  [[nodiscard]] std::size_t size() const noexcept { return polynomial.size(); }

  auto& operator[](const std::size_t& at) { return polynomial[at]; }

  const auto& operator[](const std::size_t& at) const { return polynomial[at]; }

  Polynomial operator+=(const Polynomial& other) {
    polynomial.resize(std::max(polynomial.size(), other.size()));
    for (std::size_t i = 0; i < other.size(); ++i) polynomial[i] += other[i];
    return *this;
  }

  template <typename T1>
  Polynomial& operator+=(const T1& other) {
    return *this += Polynomial(other);
  }

  Polynomial operator-=(const Polynomial& other) {
    polynomial.resize(std::max(polynomial.size(), other.size()));
    for (std::size_t i = 0; i < other.size()(); ++i) polynomial[i] -= other[i];
    return *this;
  }

  template <typename T1>
  Polynomial& operator-=(const T1& other) {
    return *this -= Polynomial(other);
  }
};

template <typename T>
Polynomial<T> operator+(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return Polynomial<T>(lhs) += rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator+(const Polynomial<T1>& lhs, T2 rhs) {
  return Polynomial<T1>(lhs) += rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator+(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) += rhs;
}

template <typename T>
Polynomial<T> operator-(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return Polynomial<T>(lhs) -= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator-(const Polynomial<T1>& lhs, T2 rhs) {
  return Polynomial<T1>(lhs) -= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator-(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) -= rhs;
}

template <typename T>
Polynomial<T> operator*(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return Polynomial<T>(lhs) *= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator*(const Polynomial<T1>& lhs, T2 rhs) {
  return Polynomial<T1>(lhs) *= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator*(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) *= rhs;
}

template <typename T>
Polynomial<T> operator/(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return Polynomial<T>(lhs) /= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator/(const Polynomial<T1>& lhs, T2 rhs) {
  return Polynomial<T1>(lhs) /= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator/(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) /= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator^(const Polynomial<T1>& lhs, T2 rhs) {
  return Polynomial<T1>(lhs) ^= rhs;
}

template <typename T1, typename T2>
Polynomial<T1> operator^(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) ^= rhs;
}

template <typename T>
bool operator==(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return lhs() == rhs();
}

template <typename T1, typename T2>
bool operator==(const Polynomial<T1>& lhs, T2 rhs) {
  return lhs == Polynomial<T1>(rhs);
}

template <typename T1, typename T2>
bool operator==(T2 lhs, const Polynomial<T1>& rhs) {
  return Polynomial<T1>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator!=(const Polynomial<T1>& lhs, T2 rhs) {
  return !(lhs == rhs);
}

template <typename T1, typename T2>
bool operator!=(T2 lhs, const Polynomial<T1>& rhs) {
  return !(lhs == rhs);
}

#endif