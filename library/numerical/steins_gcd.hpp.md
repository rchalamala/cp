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
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  _extendedVerifiedWith:
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
    links: []
  bundledCode: "#line 1 \"library/numerical/steins_gcd.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <type_traits>\n#include <utility>\n#line 1 \"library/numerical/trailing_zero_bits.hpp\"\
    \n\n\n\n#line 5 \"library/numerical/trailing_zero_bits.hpp\"\n\ntemplate<typename\
    \ T> T trailing_zero_bits(T element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \tT result = 0;\n\tfor(; (element & 1) ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\
    \t}\n\treturn result;\n}\n\n\n#line 8 \"library/numerical/steins_gcd.hpp\"\n\n\
    template<typename T1, typename T2> constexpr typename std::common_type<T1, T2>::type\
    \ steins_gcd(const T1& u_x, const T2& u_y)\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\ttypename std::common_type<T1, T2>::type\
    \ x{u_x}, y{u_y};\n\tif(x == 0)\n\t{\n\t\treturn y;\n\t}\n\tif(y == 0)\n\t{\n\t\
    \treturn x;\n\t}\n\ttypename std::common_type<T1, T2>::type a{trailing_zero_bits(x)},\
    \ b{trailing_zero_bits(y)};\n\tx >>= a;\n\ty >>= b;\n\twhile(true)\n\t{\n\t\t\
    if(x < y)\n\t\t{\n\t\t\tstd::swap(x, y);\n\t\t}\n\t\tx -= y;\n\t\tif(!x)\n\t\t\
    {\n\t\t\treturn y << std::min(a, b);\n\t\t}\n\t\tx >>= trailing_zero_bits(x);\n\
    \t}\n}\n\n\n"
  code: "#ifndef STEINS_GCD_HPP\n#define STEINS_GCD_HPP\n\n#include <algorithm>\n\
    #include <type_traits>\n#include <utility>\n#include \"trailing_zero_bits.hpp\"\
    \n\ntemplate<typename T1, typename T2> constexpr typename std::common_type<T1,\
    \ T2>::type steins_gcd(const T1& u_x, const T2& u_y)\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\ttypename std::common_type<T1, T2>::type\
    \ x{u_x}, y{u_y};\n\tif(x == 0)\n\t{\n\t\treturn y;\n\t}\n\tif(y == 0)\n\t{\n\t\
    \treturn x;\n\t}\n\ttypename std::common_type<T1, T2>::type a{trailing_zero_bits(x)},\
    \ b{trailing_zero_bits(y)};\n\tx >>= a;\n\ty >>= b;\n\twhile(true)\n\t{\n\t\t\
    if(x < y)\n\t\t{\n\t\t\tstd::swap(x, y);\n\t\t}\n\t\tx -= y;\n\t\tif(!x)\n\t\t\
    {\n\t\t\treturn y << std::min(a, b);\n\t\t}\n\t\tx >>= trailing_zero_bits(x);\n\
    \t}\n}\n\n#endif"
  dependsOn:
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/steins_gcd.hpp
  requiredBy:
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-26 00:48:11-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/numerical/steins_gcd.hpp
layout: document
redirect_from:
- /library/library/numerical/steins_gcd.hpp
- /library/library/numerical/steins_gcd.hpp.html
title: library/numerical/steins_gcd.hpp
---
