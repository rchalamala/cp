---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"library/general/prng.hpp\"\n\n\n\n#include <chrono>\n#include\
    \ <type_traits>\n#include <random>\n\ninline std::mt19937_64& getPRNG()\n{\n\t\
    #ifdef LOCAL\n\tstatic std::mt19937_64 PRNG{0};\n\t#else\n\tstatic std::mt19937_64\
    \ PRNG{static_cast<std::uint_fast64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \t#endif\n\treturn PRNG;\n}\n\ntemplate<typename T1, typename T2> typename std::common_type<T1,\
    \ T2>::type getUID(const T1& uLow, const T2& uHigh)\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\ttypename std::common_type<T1, T2>::type\
    \ low{uLow}, high{uHigh};\n\treturn std::uniform_int_distribution<typename std::common_type<T1,\
    \ T2>::type>(low, high)(getPRNG());\n}\n\ntemplate<typename T1, typename T2> typename\
    \ std::common_type<T1, T2>::type getURD(const T1& uLow, const T2& uHigh)\n{\n\t\
    static_assert(std::is_floating_point_v<T1>);\n\tstatic_assert(std::is_floating_point_v<T2>);\n\
    \ttypename std::common_type<T1, T2>::type low{uLow}, high{uHigh};\n\treturn std::uniform_real_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(getPRNG());\n}\n\n\n"
  code: "#ifndef PRNG_HPP\n#define PRNG_HPP\n\n#include <chrono>\n#include <type_traits>\n\
    #include <random>\n\ninline std::mt19937_64& getPRNG()\n{\n\t#ifdef LOCAL\n\t\
    static std::mt19937_64 PRNG{0};\n\t#else\n\tstatic std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>(\
    \ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \t#endif\n\treturn PRNG;\n}\n\ntemplate<typename T1, typename T2> typename std::common_type<T1,\
    \ T2>::type getUID(const T1& uLow, const T2& uHigh)\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\
    \tstatic_assert(std::is_integral_v<T2>);\n\ttypename std::common_type<T1, T2>::type\
    \ low{uLow}, high{uHigh};\n\treturn std::uniform_int_distribution<typename std::common_type<T1,\
    \ T2>::type>(low, high)(getPRNG());\n}\n\ntemplate<typename T1, typename T2> typename\
    \ std::common_type<T1, T2>::type getURD(const T1& uLow, const T2& uHigh)\n{\n\t\
    static_assert(std::is_floating_point_v<T1>);\n\tstatic_assert(std::is_floating_point_v<T2>);\n\
    \ttypename std::common_type<T1, T2>::type low{uLow}, high{uHigh};\n\treturn std::uniform_real_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(getPRNG());\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/prng.hpp
  requiredBy:
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-28 23:42:17-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/prng.hpp
layout: document
redirect_from:
- /library/library/general/prng.hpp
- /library/library/general/prng.hpp.html
title: library/general/prng.hpp
---
