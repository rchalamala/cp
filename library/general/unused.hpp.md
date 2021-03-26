---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/general/base.hpp
    title: library/general/base.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':x:'
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  - icon: ':question:'
    path: library/numerical/primality/miller_rabin_primality_test.hpp
    title: library/numerical/primality/miller_rabin_primality_test.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/optimized_rho_factorization.test.cpp
    title: verification/numerical/factors/optimized_rho_factorization.test.cpp
  - icon: ':x:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/general/unused.hpp"




    template<class... T> void unused(T&& ...) {}



    '
  code: '#ifndef UNUSED_HPP

    #define UNUSED_HPP


    template<class... T> void unused(T&& ...) {}


    #endif'
  dependsOn: []
  isVerificationFile: false
  path: library/general/unused.hpp
  requiredBy:
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/general/base.hpp
  timestamp: '2021-03-20 14:38:53-06:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/unused.hpp
layout: document
redirect_from:
- /library/library/general/unused.hpp
- /library/library/general/unused.hpp.html
title: library/general/unused.hpp
---
