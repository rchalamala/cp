---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/general/gcc_extensions.hpp
    title: library/general/gcc_extensions.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':warning:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
  - icon: ':warning:'
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  - icon: ':warning:'
    path: library/numerical/factors/pollards_rho_factorization.hpp
    title: library/numerical/factors/pollards_rho_factorization.hpp
  - icon: ':warning:'
    path: library/numerical/primality/miller_rabin_primality_test.hpp
    title: library/numerical/primality/miller_rabin_primality_test.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/general/base.hpp"




    #include <bits/stdc++.h>

    #line 1 "library/general/gcc_extensions.hpp"




    #ifdef __GNUC__


    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    #include <ext/rope>


    using namespace __gnu_pbds;

    using namespace __gnu_cxx;


    template<typename T> using orderedSet = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

    template<typename T> using orderedMultiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


    #endif



    #line 6 "library/general/base.hpp"


    #define mp std::make_pair

    #define mt std::make_tuple

    #define pb push_back

    #define eb emplace_back

    #define ff first

    #define ss second


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;



    '
  code: '#ifndef BASE_HPP

    #define BASE_HPP


    #include <bits/stdc++.h>

    #include "gcc_extensions.hpp"


    #define mp std::make_pair

    #define mt std::make_tuple

    #define pb push_back

    #define eb emplace_back

    #define ff first

    #define ss second


    using ll = long long;

    using ull = unsigned long long;

    using ld = long double;


    #endif'
  dependsOn:
  - library/general/gcc_extensions.hpp
  isVerificationFile: false
  path: library/general/base.hpp
  requiredBy:
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/primality/miller_rabin_primality_test.hpp
  timestamp: '2021-05-06 17:00:48-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/base.hpp
layout: document
redirect_from:
- /library/library/general/base.hpp
- /library/library/general/base.hpp.html
title: library/general/base.hpp
---