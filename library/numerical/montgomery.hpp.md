---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/primality/miller_rabin_primality_test.hpp
    title: library/numerical/primality/miller_rabin_primality_test.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/optimized_rho_factorization.test.cpp
    title: verification/numerical/factors/optimized_rho_factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/optimized_rho_factorization.test.cpp
    title: verification/numerical/factors/optimized_rho_factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://cp-algorithms.com/algebra/montgomery_multiplication.html
    - https://judge.yosupo.jp/submission/38126
  bundledCode: "#line 1 \"library/numerical/montgomery.hpp\"\n\n\n\n#include <limits>\n\
    #include <type_traits>\n\n#line 1 \"library/numerical/trailing_zero_bits.hpp\"\
    \n\n\n\n#include <cstdint>\n#line 6 \"library/numerical/trailing_zero_bits.hpp\"\
    \n\ntemplate<typename T> std::uint64_t trailing_zero_bits(const T& element)\n\
    {\n\tstatic_assert(std::is_integral_v<T>);\n\treturn __builtin_ctzll(element);\n\
    }\n\n/*\ntemplate<typename T> T trailing_zero_bits(T element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \tT result{};\n\tfor(; (element & 1) ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\
    \t}\n\treturn result;\n}\n*/\n\n\n#line 8 \"library/numerical/montgomery.hpp\"\
    \n/*\n//https://cp-algorithms.com/algebra/montgomery_multiplication.html\ntemplate<typename\
    \ T1, typename T2, std::size_t Bits> struct BigMultiplication\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\tstatic_assert(std::is_unsigned<T1>);\n\
    \tstatic_assert(std::is_unsigned<T2>);\n\n\tT high, low;\n\n\tstatic BigMultiplication\
    \ multiply(const T& x, const T& y)\n\t{\n\t\tT2 a = x >> Bits, b = x, c = y >>\
    \ Bits, d = y;\n\t\tT1 ac = static_cast<T1>(a) * c, ad = static_cast<T1>(a) *\
    \ d, T1 bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b) * d;\n\t\tT carry\
    \ = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc))\
    \ + (bd >> Bits);\n\t\tT high = ac + (ad >> Bits) + (bc >> Bits) + (carry >> Bits);\n\
    \t\tT low = (ad << Bits) + (bc << Bits) + bd;\n\t\treturn {high, low};\n\t}\n\
    };\n\ntemplate<typename T1, typename T2, std::size_t Bits> struct Montgomery\n\
    {\n\tstatic_assert(std::is_integral_v<T>);\n\n\tT1 n;\n\n\tstatic T1 modulus,\
    \ inverse{1};\n\n\tstatic T1 initialize(const T1& uN)\n\t{\n\t\tx %= mod;\n\t\t\
    for (int i = 0; i < 128; i++) {\n\t\t\tx <<= 1;\n\t\t\tif (x >= mod)\n\t\t\t\t\
    x -= mod;\n\t\t}\n\t\treturn x;\n\t}\n\n\tstatic  redc(const BigMultiplication<T1,\
    \ T2, Bits>& x)\n\t{\n\t\tT1 q = x.low * inverse, a = BigMultiplication<T1, T2,\
    \ Bits>::multiply(q, modulus).high;\n\t\treturn (x.high < a ? (x.high + modulus\
    \ - q) : x.high - q);\n\t}\n\n\tstatic void set_modulus(const T1& uModulus)\n\t\
    {\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(std::uint_fast16_t i = 0;\
    \ i < 6; ++i)\n\t\t{ inverse *= 2 - modulus * inverse; }\n\t}\n\n\texplicit Montgomery(const\
    \ T1& uN) : n{initialize(uN)}\n\t{\n\t}\n\n\tT1 value() const\n\t{\n\t\treturn\
    \ redc(n);\n\t}\n\n\tMontgomery& operator+=(const Montgomery& other)\n\t{\n\t\t\
    n += other.n;\n\t\tif(n >= modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\
    \t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\tn = redc(static_cast<uli>(n)\
    \ * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator+(const Montgomery&\
    \ other)\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\n\tMontgomery& operator*(const\
    \ Montgomery& other)\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\n};\n\
    \nstd::uint_fast64_t Montgomery::modulus{};\n, Montgomery::inverse{\n};\n*/\n\n\
    // https://judge.yosupo.jp/submission/38126\nstruct Montgomery\n{\n\tuint64_t\
    \ n;\n\tstatic uint64_t modulus, inverse, r2;\n\n\tMontgomery() : n{0}\n\t{\n\t\
    }\n\n\tMontgomery(const uint64_t& x) : n{init(x)}\n\t{\n\t}\n\n\tstatic uint64_t\
    \ init(const uint64_t& w)\n\t{\n\t\treturn redc(__uint128_t(w) * r2);\n\t}\n\n\
    \tstatic void set_modulus(const uint64_t& m)\n\t{\n\t\tmodulus = inverse = m;\n\
    \t\tfor(int i{}; i < 5; i++)\n\t\t{ inverse *= 2 - inverse * m; }\n\t\tr2 = -__uint128_t(m)\
    \ % m;\n\t}\n\n\tstatic uint64_t redc(const __uint128_t& x)\n\t{\n\t\tuint64_t\
    \ y{uint64_t(x >> 64) - uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus)\
    \ >> 64)};\n\t\treturn int64_t(y) < 0 ? y + modulus : y;\n\t}\n\n\tMontgomery&\
    \ operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n - modulus;\n\t\t\
    if(int64_t(n) < 0)\n\t\t{ n += modulus; }\n\t\treturn *this;\n\t}\n\n\tMontgomery&\
    \ operator+(const Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this)\
    \ += other;\n\t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\
    \tn = redc(__uint128_t(n) * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery&\
    \ operator*(const Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this)\
    \ *= other;\n\t}\n\n\tuint64_t value() const\n\t{\n\t\treturn redc(n);\n\t}\n\
    };\n\nuint64_t Montgomery::modulus, Montgomery::inverse, Montgomery::r2;\n\n\n"
  code: "#ifndef MONTGOMERY_HPP\n#define MONTGOMERY_HPP\n\n#include <limits>\n#include\
    \ <type_traits>\n\n#include \"trailing_zero_bits.hpp\"\n/*\n//https://cp-algorithms.com/algebra/montgomery_multiplication.html\n\
    template<typename T1, typename T2, std::size_t Bits> struct BigMultiplication\n\
    {\n\tstatic_assert(std::is_integral_v<T1>);\n\tstatic_assert(std::is_integral_v<T2>);\n\
    \tstatic_assert(std::is_unsigned<T1>);\n\tstatic_assert(std::is_unsigned<T2>);\n\
    \n\tT high, low;\n\n\tstatic BigMultiplication multiply(const T& x, const T& y)\n\
    \t{\n\t\tT2 a = x >> Bits, b = x, c = y >> Bits, d = y;\n\t\tT1 ac = static_cast<T1>(a)\
    \ * c, ad = static_cast<T1>(a) * d, T1 bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b)\
    \ * d;\n\t\tT carry = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc))\
    \ + (bd >> Bits);\n\t\tT high = ac + (ad >> Bits) + (bc >> Bits) + (carry >> Bits);\n\
    \t\tT low = (ad << Bits) + (bc << Bits) + bd;\n\t\treturn {high, low};\n\t}\n\
    };\n\ntemplate<typename T1, typename T2, std::size_t Bits> struct Montgomery\n\
    {\n\tstatic_assert(std::is_integral_v<T>);\n\n\tT1 n;\n\n\tstatic T1 modulus,\
    \ inverse{1};\n\n\tstatic T1 initialize(const T1& uN)\n\t{\n\t\tx %= mod;\n\t\t\
    for (int i = 0; i < 128; i++) {\n\t\t\tx <<= 1;\n\t\t\tif (x >= mod)\n\t\t\t\t\
    x -= mod;\n\t\t}\n\t\treturn x;\n\t}\n\n\tstatic  redc(const BigMultiplication<T1,\
    \ T2, Bits>& x)\n\t{\n\t\tT1 q = x.low * inverse, a = BigMultiplication<T1, T2,\
    \ Bits>::multiply(q, modulus).high;\n\t\treturn (x.high < a ? (x.high + modulus\
    \ - q) : x.high - q);\n\t}\n\n\tstatic void set_modulus(const T1& uModulus)\n\t\
    {\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(std::uint_fast16_t i = 0;\
    \ i < 6; ++i)\n\t\t{ inverse *= 2 - modulus * inverse; }\n\t}\n\n\texplicit Montgomery(const\
    \ T1& uN) : n{initialize(uN)}\n\t{\n\t}\n\n\tT1 value() const\n\t{\n\t\treturn\
    \ redc(n);\n\t}\n\n\tMontgomery& operator+=(const Montgomery& other)\n\t{\n\t\t\
    n += other.n;\n\t\tif(n >= modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\
    \t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\tn = redc(static_cast<uli>(n)\
    \ * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator+(const Montgomery&\
    \ other)\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\n\tMontgomery& operator*(const\
    \ Montgomery& other)\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\n};\n\
    \nstd::uint_fast64_t Montgomery::modulus{};\n, Montgomery::inverse{\n};\n*/\n\n\
    // https://judge.yosupo.jp/submission/38126\nstruct Montgomery\n{\n\tuint64_t\
    \ n;\n\tstatic uint64_t modulus, inverse, r2;\n\n\tMontgomery() : n{0}\n\t{\n\t\
    }\n\n\tMontgomery(const uint64_t& x) : n{init(x)}\n\t{\n\t}\n\n\tstatic uint64_t\
    \ init(const uint64_t& w)\n\t{\n\t\treturn redc(__uint128_t(w) * r2);\n\t}\n\n\
    \tstatic void set_modulus(const uint64_t& m)\n\t{\n\t\tmodulus = inverse = m;\n\
    \t\tfor(int i{}; i < 5; i++)\n\t\t{ inverse *= 2 - inverse * m; }\n\t\tr2 = -__uint128_t(m)\
    \ % m;\n\t}\n\n\tstatic uint64_t redc(const __uint128_t& x)\n\t{\n\t\tuint64_t\
    \ y{uint64_t(x >> 64) - uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus)\
    \ >> 64)};\n\t\treturn int64_t(y) < 0 ? y + modulus : y;\n\t}\n\n\tMontgomery&\
    \ operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n - modulus;\n\t\t\
    if(int64_t(n) < 0)\n\t\t{ n += modulus; }\n\t\treturn *this;\n\t}\n\n\tMontgomery&\
    \ operator+(const Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this)\
    \ += other;\n\t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\
    \tn = redc(__uint128_t(n) * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery&\
    \ operator*(const Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this)\
    \ *= other;\n\t}\n\n\tuint64_t value() const\n\t{\n\t\treturn redc(n);\n\t}\n\
    };\n\nuint64_t Montgomery::modulus, Montgomery::inverse, Montgomery::r2;\n\n#endif"
  dependsOn:
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/montgomery.hpp
  requiredBy:
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-28 23:42:17-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/numerical/montgomery.hpp
layout: document
redirect_from:
- /library/library/numerical/montgomery.hpp
- /library/library/numerical/montgomery.hpp.html
title: library/numerical/montgomery.hpp
---
