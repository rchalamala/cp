---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/general/unused.hpp
    title: library/general/unused.hpp
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
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/general/base.hpp"




    #include <cassert>

    #include <cctype>

    #include <cfloat>

    #include <climits>

    #include <cmath>

    #include <cstdarg>

    #include <cstddef>

    #include <cstdio>

    #include <cstdlib>

    #include <cstring>

    #include <ctime>


    #if __cplusplus >= 201103L


    #include <cstdint>


    #endif


    #include <algorithm>

    #include <bitset>

    #include <complex>

    #include <deque>

    #include <exception>

    #include <fstream>

    #include <functional>

    #include <iomanip>

    #include <ios>

    #include <iosfwd>

    #include <iostream>

    #include <istream>

    #include <iterator>

    #include <limits>

    #include <list>

    #include <map>

    #include <numeric>

    #include <ostream>

    #include <queue>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <typeinfo>

    #include <utility>

    #include <valarray>

    #include <vector>


    #if __cplusplus >= 201103L


    #include <type_traits>

    #include <chrono>

    #include <initializer_list>

    #include <tuple>

    #include <cstdint>

    #include <cuchar>

    #include <array>

    #include <forward_list>

    #include <unordered_set>

    #include <unordered_map>

    #include <random>

    #include <ratio>

    #include <thread>

    #include <mutex>


    #endif


    #line 1 "library/general/unused.hpp"




    template<class... T> void unused(T&& ...)

    {

    }



    #line 70 "library/general/base.hpp"


    #define ALL(set) std::begin(set), std::end(set)

    #define RALL(set) std::rbegin(set), std::rend(set)


    #define mp std::make_pair

    #define mt std::make_tuple

    #define pb push_back

    #define eb emplace_back

    #define ff first

    #define ss second

    #define lb lower_bound

    #define ub upper_bound


    using ll = long long;

    using pll = std::pair<long long, long long>;

    using vll = std::vector<long long>;


    using ull = unsigned long long;

    using pull = std::pair<unsigned long long, unsigned long long>;

    using vull = std::vector<unsigned long long>;


    using ld = long double;

    using pld = std::pair<long double, long double>;

    using vld = std::vector<long double>;


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


    #ifdef __SIZEOF_INT128__


    using li = __int128;

    using pli = std::pair<__int128, __int128>;

    using vli = std::vector<__int128>;


    using uli = unsigned __int128;

    using puli = std::pair<unsigned __int128, unsigned __int128>;

    using vuli = std::vector<unsigned __int128>;


    #endif



    '
  code: '#ifndef BASE_HPP

    #define BASE_HPP


    #include <cassert>

    #include <cctype>

    #include <cfloat>

    #include <climits>

    #include <cmath>

    #include <cstdarg>

    #include <cstddef>

    #include <cstdio>

    #include <cstdlib>

    #include <cstring>

    #include <ctime>


    #if __cplusplus >= 201103L


    #include <cstdint>


    #endif


    #include <algorithm>

    #include <bitset>

    #include <complex>

    #include <deque>

    #include <exception>

    #include <fstream>

    #include <functional>

    #include <iomanip>

    #include <ios>

    #include <iosfwd>

    #include <iostream>

    #include <istream>

    #include <iterator>

    #include <limits>

    #include <list>

    #include <map>

    #include <numeric>

    #include <ostream>

    #include <queue>

    #include <set>

    #include <sstream>

    #include <stack>

    #include <string>

    #include <typeinfo>

    #include <utility>

    #include <valarray>

    #include <vector>


    #if __cplusplus >= 201103L


    #include <type_traits>

    #include <chrono>

    #include <initializer_list>

    #include <tuple>

    #include <cstdint>

    #include <cuchar>

    #include <array>

    #include <forward_list>

    #include <unordered_set>

    #include <unordered_map>

    #include <random>

    #include <ratio>

    #include <thread>

    #include <mutex>


    #endif


    #include "unused.hpp"


    #define ALL(set) std::begin(set), std::end(set)

    #define RALL(set) std::rbegin(set), std::rend(set)


    #define mp std::make_pair

    #define mt std::make_tuple

    #define pb push_back

    #define eb emplace_back

    #define ff first

    #define ss second

    #define lb lower_bound

    #define ub upper_bound


    using ll = long long;

    using pll = std::pair<long long, long long>;

    using vll = std::vector<long long>;


    using ull = unsigned long long;

    using pull = std::pair<unsigned long long, unsigned long long>;

    using vull = std::vector<unsigned long long>;


    using ld = long double;

    using pld = std::pair<long double, long double>;

    using vld = std::vector<long double>;


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


    #ifdef __SIZEOF_INT128__


    using li = __int128;

    using pli = std::pair<__int128, __int128>;

    using vli = std::vector<__int128>;


    using uli = unsigned __int128;

    using puli = std::pair<unsigned __int128, unsigned __int128>;

    using vuli = std::vector<unsigned __int128>;


    #endif


    #endif

    '
  dependsOn:
  - library/general/unused.hpp
  isVerificationFile: false
  path: library/general/base.hpp
  requiredBy:
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-28 23:42:17-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/base.hpp
layout: document
redirect_from:
- /library/library/general/base.hpp
- /library/library/general/base.hpp.html
title: library/general/base.hpp
---
