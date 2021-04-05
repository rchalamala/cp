---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/general/base.hpp
    title: library/general/base.hpp
  - icon: ':x:'
    path: library/numerical/list_of_primes.hpp
    title: library/numerical/list_of_primes.hpp
  - icon: ':x:'
    path: library/numerical/montgomery.hpp
    title: library/numerical/montgomery.hpp
  - icon: ':x:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  - icon: ':x:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':x:'
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verification/numerical/factors/optimized_rho_factorization.test.cpp
    title: verification/numerical/factors/optimized_rho_factorization.test.cpp
  - icon: ':x:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\n\n\n#include <limits>\n#include <type_traits>\n#include <vector>\n\n#line\
    \ 1 \"library/general/base.hpp\"\n\n\n\n#include <cassert>\n#include <cctype>\n\
    #include <cfloat>\n#include <climits>\n#include <cmath>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n\n#if __cplusplus >= 201103L\n\n#include <cstdint>\n\n#endif\n\
    \n#include <algorithm>\n#include <bitset>\n#include <complex>\n#include <deque>\n\
    #include <exception>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#line 36 \"library/general/base.hpp\"\n#include <list>\n#include\
    \ <map>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <string>\n#include <typeinfo>\n\
    #include <utility>\n#include <valarray>\n#line 49 \"library/general/base.hpp\"\
    \n\n#if __cplusplus >= 201103L\n\n#line 53 \"library/general/base.hpp\"\n#include\
    \ <chrono>\n#include <initializer_list>\n#include <tuple>\n#include <cstdint>\n\
    #include <cuchar>\n#include <array>\n#include <forward_list>\n#include <unordered_set>\n\
    #include <unordered_map>\n#include <random>\n#include <ratio>\n#include <thread>\n\
    #include <mutex>\n\n#endif\n\n#define ALL(set) std::begin(set), std::end(set)\n\
    #define RALL(set) std::rbegin(set), std::rend(set)\n\n#define mp std::make_pair\n\
    #define mt std::make_tuple\n#define pb push_back\n#define eb emplace_back\n#define\
    \ ff first\n#define ss second\n\nusing ll = long long;\nusing pll = std::pair<long\
    \ long, long long>;\nusing vll = std::vector<long long>;\n\nusing ull = unsigned\
    \ long long;\nusing pull = std::pair<unsigned long long, unsigned long long>;\n\
    using vull = std::vector<unsigned long long>;\n\nusing ld = long double;\nusing\
    \ pld = std::pair<long double, long double>;\nusing vld = std::vector<long double>;\n\
    \n#ifdef __GNUC__\n\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/rope>\n\nusing namespace __gnu_pbds;\nusing namespace __gnu_cxx;\n\
    \ntemplate<typename T> using orderedSet = __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<typename T> using orderedMultiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \n#endif\n\n\n#line 1 \"library/numerical/list_of_primes.hpp\"\n\n\n\n#include\
    \ <array>\n\ninline constexpr std::array<std::uint_fast16_t, 16> smallPrimes{2,\
    \ 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};\ninline constexpr\
    \ std::array<std::uint_fast16_t, 32> mediumPrimes{2, 3, 5, 7, 11, 13, 17, 19,\
    \ 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,\
    \ 107, 109, 113, 127, 131};\ninline constexpr std::array<std::uint_fast16_t, 64>\
    \ largePrimes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,\
    \ 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,\
    \ 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229,\
    \ 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311};\n\n\n\
    #line 1 \"library/numerical/montgomery.hpp\"\n\n\n\n#include <cstdint>\n#line\
    \ 7 \"library/numerical/montgomery.hpp\"\n\n#line 1 \"library/numerical/trailing_zero_bits.hpp\"\
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
    \ Montgomery::inverse, Montgomery::r2;\n\n\n#line 12 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\nnamespace primality\n{\n\n\ttemplate<typename T> Montgomery power(const Montgomery&\
    \ base, T exponent)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tstatic_assert(std::is_unsigned_v<T>);\n\
    \t\tMontgomery mBase = base, result(1);\n\t\twhile(exponent)\n\t\t{\n\t\t\tif(exponent\
    \ & 1)\n\t\t\t{ result *= mBase; }\n\t\t\tmBase *= mBase;\n\t\t\texponent >>=\
    \ 1;\n\t\t}\n\t\treturn result;\n\t}\n\n\ttemplate<typename T, std::size_t BasesSize\
    \ = 7> bool miller_rabin(const T& n, const bool& checkBaseCases = true, const\
    \ std::array<T, BasesSize>& A = {2, 325, 9375, 28178, 450775, 9780504, 1795265022})\n\
    \t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tstatic_assert(std::is_unsigned_v<T>);\n\
    \t\tif(checkBaseCases)\n\t\t{\n\t\t\tif(n <= 1)\n\t\t\t{ return false; }\n\t\t\
    \tfor(const auto& a : largePrimes)\n\t\t\t{\n\t\t\t\tif(a > n)\n\t\t\t\t{ break;\
    \ }\n\t\t\t\tif(n == a)\n\t\t\t\t{\n\t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\t\
    if(n % a == 0)\n\t\t\t\t{ return false; }\n\t\t\t}\n\t\t}\n\t\tif(Montgomery::modulus\
    \ != n)\n\t\t{ Montgomery::set_modulus(n); }\n\t\tT bits{trailing_zero_bits(n\
    \ - 1)}, d{(n - 1) >> bits};\n\t\tMontgomery one{1}, negativeOne{n - 1};\n\t\t\
    for(const T& a : A)\n\t\t{\n\t\t\tMontgomery mA{a};\n\t\t\tif(mA.n)\n\t\t\t{\n\
    \t\t\t\tT i{};\n\t\t\t\tMontgomery x{power(mA, d)};\n\t\t\t\tif(x.n == one.n ||\
    \ x.n == negativeOne.n)\n\t\t\t\t{ continue; }\n\t\t\t\tfor(; x.n != one.n &&\
    \ x.n != negativeOne.n && i < bits; ++i)\n\t\t\t\t{\n\t\t\t\t\tif(x.n == one.n)\n\
    \t\t\t\t\t{ return false; }\n\t\t\t\t\tif(x.n == negativeOne.n)\n\t\t\t\t\t{ break;\
    \ }\n\t\t\t\t\tx *= x;\n\t\t\t\t}\n\t\t\t\tif((i == bits) ^ (x.n == one.n))\n\t\
    \t\t\t{ return false; }\n\t\t\t}\n\t\t\telse\n\t\t\t{ return true; }\n\t\t}\n\t\
    \treturn true;\n\t}\n}\n\n\n"
  code: "#ifndef MILLER_RABIN_PRIMALITY_TEST_HPP\n#define MILLER_RABIN_PRIMALITY_TEST_HPP\n\
    \n#include <limits>\n#include <type_traits>\n#include <vector>\n\n#include \"\
    ../../general/base.hpp\"\n#include \"../list_of_primes.hpp\"\n#include \"../montgomery.hpp\"\
    \n#include \"../trailing_zero_bits.hpp\"\n\nnamespace primality\n{\n\n\ttemplate<typename\
    \ T> Montgomery power(const Montgomery& base, T exponent)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tstatic_assert(std::is_unsigned_v<T>);\n\t\tMontgomery mBase = base, result(1);\n\
    \t\twhile(exponent)\n\t\t{\n\t\t\tif(exponent & 1)\n\t\t\t{ result *= mBase; }\n\
    \t\t\tmBase *= mBase;\n\t\t\texponent >>= 1;\n\t\t}\n\t\treturn result;\n\t}\n\
    \n\ttemplate<typename T, std::size_t BasesSize = 7> bool miller_rabin(const T&\
    \ n, const bool& checkBaseCases = true, const std::array<T, BasesSize>& A = {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022})\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tstatic_assert(std::is_unsigned_v<T>);\n\t\tif(checkBaseCases)\n\t\t{\n\t\t\
    \tif(n <= 1)\n\t\t\t{ return false; }\n\t\t\tfor(const auto& a : largePrimes)\n\
    \t\t\t{\n\t\t\t\tif(a > n)\n\t\t\t\t{ break; }\n\t\t\t\tif(n == a)\n\t\t\t\t{\n\
    \t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\tif(n % a == 0)\n\t\t\t\t{ return false;\
    \ }\n\t\t\t}\n\t\t}\n\t\tif(Montgomery::modulus != n)\n\t\t{ Montgomery::set_modulus(n);\
    \ }\n\t\tT bits{trailing_zero_bits(n - 1)}, d{(n - 1) >> bits};\n\t\tMontgomery\
    \ one{1}, negativeOne{n - 1};\n\t\tfor(const T& a : A)\n\t\t{\n\t\t\tMontgomery\
    \ mA{a};\n\t\t\tif(mA.n)\n\t\t\t{\n\t\t\t\tT i{};\n\t\t\t\tMontgomery x{power(mA,\
    \ d)};\n\t\t\t\tif(x.n == one.n || x.n == negativeOne.n)\n\t\t\t\t{ continue;\
    \ }\n\t\t\t\tfor(; x.n != one.n && x.n != negativeOne.n && i < bits; ++i)\n\t\t\
    \t\t{\n\t\t\t\t\tif(x.n == one.n)\n\t\t\t\t\t{ return false; }\n\t\t\t\t\tif(x.n\
    \ == negativeOne.n)\n\t\t\t\t\t{ break; }\n\t\t\t\t\tx *= x;\n\t\t\t\t}\n\t\t\t\
    \tif((i == bits) ^ (x.n == one.n))\n\t\t\t\t{ return false; }\n\t\t\t}\n\t\t\t\
    else\n\t\t\t{ return true; }\n\t\t}\n\t\treturn true;\n\t}\n}\n\n#endif"
  dependsOn:
  - library/general/base.hpp
  - library/numerical/list_of_primes.hpp
  - library/numerical/montgomery.hpp
  - library/numerical/trailing_zero_bits.hpp
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/primality/miller_rabin_primality_test.hpp
  requiredBy:
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  timestamp: '2021-04-05 00:55:31-06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/numerical/primality/miller_rabin_primality_test.hpp
layout: document
redirect_from:
- /library/library/numerical/primality/miller_rabin_primality_test.hpp
- /library/library/numerical/primality/miller_rabin_primality_test.hpp.html
title: library/numerical/primality/miller_rabin_primality_test.hpp
---
