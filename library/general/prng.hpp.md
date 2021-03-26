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
    \ <random>\n\ninline std::mt19937_64& getPRNG()\n{\n\tstatic std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>(\
    \ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \treturn PRNG;\n}\n\ntemplate<typename T> T getUID(const T& low, const T& high)\n\
    {\n\treturn std::uniform_int_distribution<T>(low, high)(getPRNG());\n}\n\ntemplate<typename\
    \ T> T getURD(const T& low, const T& high)\n{\n\treturn std::uniform_real_distribution<T>(low,\
    \ high)(getPRNG());\n}\n\n\n"
  code: "#ifndef PRNG_H\n#define PRNG_H\n\n#include <chrono>\n#include <random>\n\n\
    inline std::mt19937_64& getPRNG()\n{\n\tstatic std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>(\
    \ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \treturn PRNG;\n}\n\ntemplate<typename T> T getUID(const T& low, const T& high)\n\
    {\n\treturn std::uniform_int_distribution<T>(low, high)(getPRNG());\n}\n\ntemplate<typename\
    \ T> T getURD(const T& low, const T& high)\n{\n\treturn std::uniform_real_distribution<T>(low,\
    \ high)(getPRNG());\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/prng.hpp
  requiredBy:
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-26 00:07:57-06:00'
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
