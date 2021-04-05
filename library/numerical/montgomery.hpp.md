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
  bundledCode: "#line 1 \"library/numerical/montgomery.hpp\"\n\n\n\n#include <cstdint>\n\
    #include <limits>\n#include <type_traits>\n\n#line 1 \"library/numerical/trailing_zero_bits.hpp\"\
    \n\n\n\n#line 6 \"library/numerical/trailing_zero_bits.hpp\"\n\ntemplate<typename\
    \ T> std::uint64_t trailing_zero_bits(const T& element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \treturn __builtin_ctzll(element);\n}\n\n/*\ntemplate<typename T> T trailing_zero_bits(T\
    \ element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\tstatic_assert(std::is_unsigned_v<T>);\n\
    \tT result{};\n\tfor(; (element & 1) ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\
    \t}\n\treturn result;\n}\n*/\n\n\n#line 9 \"library/numerical/montgomery.hpp\"\
    \n\n/*//https://cp-algorithms.com/algebra/montgomery_multiplication.html\ntemplate<typename\
    \ T1, typename T2, std::size_t Bits> struct BigMultiplication\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\tstatic_assert(std::is_unsigned_v<T1>);\n\
    \tstatic_assert(std::is_unsigned_v<T2>);\n\n\tT1 high, low;\n\n\tstatic BigMultiplication\
    \ multiply(const T1& x, const T1& y)\n\t{\n\t\tT2 a = x >> Bits, b = x, c = y\
    \ >> Bits, d = y;\n\t\tT1 ac = static_cast<T1>(a) * c, ad = static_cast<T1>(a)\
    \ * d, bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b) * d;\n\t\tT1 carry\
    \ = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc))\
    \ + (bd >> Bits);\n\t\tT1 high = ac + (ad >> Bits) + (bc >> Bits) + (carry >>\
    \ Bits);\n\t\tT1 low = (ad << Bits) + (bc << Bits) + bd;\n\t\treturn {high, low};\n\
    \t}\n};\n\ntemplate<typename T1, typename T2, std::size_t Bits> struct Montgomery\n\
    {\n\n\tT1 n;\n\n\tstatic T1 modulus, inverse;\n\n\tstatic T1 redc(const BigMultiplication<T1,\
    \ T2, Bits>& x)\n\t{\n\t\tT1 q = x.low * inverse, a = BigMultiplication<T1, T2,\
    \ Bits>::multiply(q, modulus).high;\n\t\treturn (x.high < a ? (x.high + modulus\
    \ - q) : x.high - q);\n\t}\n\n\tstatic void set_modulus(const T1& uModulus)\n\t\
    {\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(std::size_t i = 0; i < __builtin_ctzll(Bits);\
    \ ++i)\n\t\t{ inverse *= 2 - modulus * inverse; }\n\t}\n\n\texplicit Montgomery(const\
    \ T1& uN) : n{uN}\n\t{\n\t\tn %= modulus;\n\t\tfor(std::size_t i = 0; i < Bits;\
    \ i++)\n\t\t{\n\t\t\tn <<= 1;\n\t\t\tif(n >= modulus)\n\t\t\t{\n\t\t\t\tn -= modulus;\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tT1 value() const\n\t{\n\t\treturn redc({0, n});\n\t}\n\
    \n\tMontgomery& operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n;\n\t\
    \tif(n >= modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator+=(const U& other)\n\t{\n\t\tn += other;\n\t\tif(n >=\
    \ modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator+(const U& other)\n\t{\n\t\treturn Montgomery{*this}\
    \ += other;\n\t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\
    \tn = redc(BigMultiplication<T1, T2, Bits>::multiply(n, other.n));\n\t\treturn\
    \ *this;\n\t}\n\n\ttemplate<typename U> Montgomery& operator*=(const U& other)\n\
    \t{\n\t\tn *= Montgomery{other};\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator*(const U& other)\n\t{\n\t\treturn Montgomery{*this}\
    \ *= other;\n\t}\n\n};\n\ntemplate<typename T1, typename T2, std::size_t Bits>\
    \ T1 Montgomery<T1, T2, Bits>::modulus{};\ntemplate<typename T1, typename T2,\
    \ std::size_t Bits> T1 Montgomery<T1, T2, Bits>::inverse{};*/\n\n// https://judge.yosupo.jp/submission/38126\n\
    struct Montgomery\n{\n\tuint64_t n;\n\tstatic uint64_t modulus, inverse, r2;\n\
    \n\tMontgomery() : n{}\n\t{\n\t}\n\n\tMontgomery(const uint64_t& uN) : n{redc(__uint128_t(uN)\
    \ * r2)}\n\t{\n\t}\n\n\tstatic void set_modulus(const uint64_t& uModulus)\n\t\
    {\n\t\tassert(uModulus >= 1 && uModulus - 1 < (std::numeric_limits<uint64_t>::max()\
    \ >> 1));\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(int i = 0; i < 6;\
    \ i++)\n\t\t{ inverse *= 2 - inverse * modulus; }\n\t\tr2 = -__uint128_t(modulus)\
    \ % modulus;\n\t}\n\n\tstatic uint64_t redc(const __uint128_t& x)\n\t{\n\t\tuint64_t\
    \ y{uint64_t(x >> 64)}, l{uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus)\
    \ >> 64)};\n\t\treturn y < l ? y + modulus - l : y - l;\n\t}\n\n\tMontgomery&\
    \ operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n;\n\t\tif(n >= modulus)\n\
    \t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator+(const\
    \ Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\
    \n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\tn = redc(__uint128_t(n)\
    \ * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator*(const Montgomery&\
    \ other) const\n\t{\n\t\treturn Montgomery(*this) *= other;\n\t}\n\n\tuint64_t\
    \ value() const\n\t{\n\t\treturn redc(n);\n\t}\n};\n\nuint64_t Montgomery::modulus{1},\
    \ Montgomery::inverse, Montgomery::r2;\n\n\n"
  code: "#ifndef MONTGOMERY_HPP\n#define MONTGOMERY_HPP\n\n#include <cstdint>\n#include\
    \ <limits>\n#include <type_traits>\n\n#include \"trailing_zero_bits.hpp\"\n\n\
    /*//https://cp-algorithms.com/algebra/montgomery_multiplication.html\ntemplate<typename\
    \ T1, typename T2, std::size_t Bits> struct BigMultiplication\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\tstatic_assert(std::is_unsigned_v<T1>);\n\
    \tstatic_assert(std::is_unsigned_v<T2>);\n\n\tT1 high, low;\n\n\tstatic BigMultiplication\
    \ multiply(const T1& x, const T1& y)\n\t{\n\t\tT2 a = x >> Bits, b = x, c = y\
    \ >> Bits, d = y;\n\t\tT1 ac = static_cast<T1>(a) * c, ad = static_cast<T1>(a)\
    \ * d, bc = static_cast<T1>(b) * c, bd = static_cast<T1>(b) * d;\n\t\tT1 carry\
    \ = static_cast<T1>(static_cast<T2>(ad)) + static_cast<T1>(static_cast<T2>(bc))\
    \ + (bd >> Bits);\n\t\tT1 high = ac + (ad >> Bits) + (bc >> Bits) + (carry >>\
    \ Bits);\n\t\tT1 low = (ad << Bits) + (bc << Bits) + bd;\n\t\treturn {high, low};\n\
    \t}\n};\n\ntemplate<typename T1, typename T2, std::size_t Bits> struct Montgomery\n\
    {\n\n\tT1 n;\n\n\tstatic T1 modulus, inverse;\n\n\tstatic T1 redc(const BigMultiplication<T1,\
    \ T2, Bits>& x)\n\t{\n\t\tT1 q = x.low * inverse, a = BigMultiplication<T1, T2,\
    \ Bits>::multiply(q, modulus).high;\n\t\treturn (x.high < a ? (x.high + modulus\
    \ - q) : x.high - q);\n\t}\n\n\tstatic void set_modulus(const T1& uModulus)\n\t\
    {\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(std::size_t i = 0; i < __builtin_ctzll(Bits);\
    \ ++i)\n\t\t{ inverse *= 2 - modulus * inverse; }\n\t}\n\n\texplicit Montgomery(const\
    \ T1& uN) : n{uN}\n\t{\n\t\tn %= modulus;\n\t\tfor(std::size_t i = 0; i < Bits;\
    \ i++)\n\t\t{\n\t\t\tn <<= 1;\n\t\t\tif(n >= modulus)\n\t\t\t{\n\t\t\t\tn -= modulus;\n\
    \t\t\t}\n\t\t}\n\t}\n\n\tT1 value() const\n\t{\n\t\treturn redc({0, n});\n\t}\n\
    \n\tMontgomery& operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n;\n\t\
    \tif(n >= modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator+=(const U& other)\n\t{\n\t\tn += other;\n\t\tif(n >=\
    \ modulus)\n\t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator+(const U& other)\n\t{\n\t\treturn Montgomery{*this}\
    \ += other;\n\t}\n\n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\
    \tn = redc(BigMultiplication<T1, T2, Bits>::multiply(n, other.n));\n\t\treturn\
    \ *this;\n\t}\n\n\ttemplate<typename U> Montgomery& operator*=(const U& other)\n\
    \t{\n\t\tn *= Montgomery{other};\n\t\treturn *this;\n\t}\n\n\ttemplate<typename\
    \ U> Montgomery& operator*(const U& other)\n\t{\n\t\treturn Montgomery{*this}\
    \ *= other;\n\t}\n\n};\n\ntemplate<typename T1, typename T2, std::size_t Bits>\
    \ T1 Montgomery<T1, T2, Bits>::modulus{};\ntemplate<typename T1, typename T2,\
    \ std::size_t Bits> T1 Montgomery<T1, T2, Bits>::inverse{};*/\n\n// https://judge.yosupo.jp/submission/38126\n\
    struct Montgomery\n{\n\tuint64_t n;\n\tstatic uint64_t modulus, inverse, r2;\n\
    \n\tMontgomery() : n{}\n\t{\n\t}\n\n\tMontgomery(const uint64_t& uN) : n{redc(__uint128_t(uN)\
    \ * r2)}\n\t{\n\t}\n\n\tstatic void set_modulus(const uint64_t& uModulus)\n\t\
    {\n\t\tassert(uModulus >= 1 && uModulus - 1 < (std::numeric_limits<uint64_t>::max()\
    \ >> 1));\n\t\tmodulus = uModulus;\n\t\tinverse = 1;\n\t\tfor(int i = 0; i < 6;\
    \ i++)\n\t\t{ inverse *= 2 - inverse * modulus; }\n\t\tr2 = -__uint128_t(modulus)\
    \ % modulus;\n\t}\n\n\tstatic uint64_t redc(const __uint128_t& x)\n\t{\n\t\tuint64_t\
    \ y{uint64_t(x >> 64)}, l{uint64_t((__uint128_t(uint64_t(x) * inverse) * modulus)\
    \ >> 64)};\n\t\treturn y < l ? y + modulus - l : y - l;\n\t}\n\n\tMontgomery&\
    \ operator+=(const Montgomery& other)\n\t{\n\t\tn += other.n;\n\t\tif(n >= modulus)\n\
    \t\t{ n -= modulus; }\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator+(const\
    \ Montgomery& other) const\n\t{\n\t\treturn Montgomery(*this) += other;\n\t}\n\
    \n\tMontgomery& operator*=(const Montgomery& other)\n\t{\n\t\tn = redc(__uint128_t(n)\
    \ * other.n);\n\t\treturn *this;\n\t}\n\n\tMontgomery& operator*(const Montgomery&\
    \ other) const\n\t{\n\t\treturn Montgomery(*this) *= other;\n\t}\n\n\tuint64_t\
    \ value() const\n\t{\n\t\treturn redc(n);\n\t}\n};\n\nuint64_t Montgomery::modulus{1},\
    \ Montgomery::inverse, Montgomery::r2;\n\n#endif"
  dependsOn:
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/montgomery.hpp
  requiredBy:
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  timestamp: '2021-03-30 13:00:21-06:00'
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
