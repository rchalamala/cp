---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/general/base.hpp
    title: library/general/base.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/unused.hpp
    title: library/general/unused.hpp
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
  bundledCode: "#line 1 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\n\n\n#include <type_traits>\n#include <vector>\n\n#line 1 \"library/general/base.hpp\"\
    \n\n\n\n#include <cassert>\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <cwchar>\n\
    #include <cwctype>\n\n#if __cplusplus >= 201103L\n\n#include <cfenv>\n#include\
    \ <cinttypes>\n#include <cstdint>\n#include <cuchar>\n\n#endif\n\n#include <algorithm>\n\
    #include <bitset>\n#include <complex>\n#include <deque>\n#include <exception>\n\
    #include <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n\
    #include <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <typeinfo>\n#include <utility>\n#include\
    \ <valarray>\n#line 63 \"library/general/base.hpp\"\n\n#if __cplusplus >= 201103L\n\
    \n#include <typeindex>\n#line 68 \"library/general/base.hpp\"\n#include <chrono>\n\
    #include <initializer_list>\n#include <tuple>\n#include <scoped_allocator>\n#include\
    \ <cstdint>\n#include <cinttypes>\n#include <system_error>\n#include <cuchar>\n\
    #include <array>\n#include <forward_list>\n#include <unordered_set>\n#include\
    \ <unordered_map>\n#include <random>\n#include <ratio>\n#include <cfenv>\n#include\
    \ <regex>\n#include <atomic>\n#include <thread>\n#include <mutex>\n#include <future>\n\
    #include <condition_variable>\n\n#endif\n\n#if __cplusplus >= 201402L\n\n#include\
    \ <shared_mutex>\n\n#endif\n\n#if __cplusplus >= 201703L\n\n#include <any>\n#include\
    \ <charconv>\n//#include <execution>\n#include <filesystem>\n#include <memory_resource>\n\
    #include <optional>\n#include <string_view>\n#include <variant>\n\n#endif\n\n\
    #if __cplusplus >= 202002L\n#include <barrier>\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <coroutine>\n#include <format>\n#include <latch>\n\
    #include <numbers>\n#include <ranges>\n#include <semaphore>\n#include <source_location>\n\
    #include <span>\n#include <stop_token>\n#include <syncstream>\n#include <version>\n\
    #endif\n\n#ifdef __GNUC__\n\n#include <ext/pb_ds/assoc_container.hpp>\n#include\
    \ <ext/pb_ds/tree_policy.hpp>\n#include <ext/rope>\n\nusing namespace __gnu_pbds;\n\
    using namespace __gnu_cxx;\n\ntemplate<typename T> using ordered_set = __gnu_pbds::tree<T,\
    \ __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    template<typename T> using ordered_multiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
    \n#endif\n\n#line 1 \"library/general/unused.hpp\"\n\n\n\ntemplate<class... T>\
    \ void unused(T&& ...)\n{\n}\n\n\n#line 144 \"library/general/base.hpp\"\n\n#define\
    \ ALL(set) std::begin(set), std::end(set)\n#define RALL(set) std::rbegin(set),\
    \ std::rend(set)\n\n#define mp std::make_pair\n#define mt std::make_tuple\n#define\
    \ pb push_back\n#define eb emplace_back\n#define ff first\n#define ss second\n\
    #define lb lower_bound\n#define ub upper_bound\n\nusing ll = long long;\nusing\
    \ pll = std::pair<long long, long long>;\nusing vll = std::vector<long long>;\n\
    \nusing ull = unsigned long long;\nusing pull = std::pair<unsigned long long,\
    \ unsigned long long>;\nusing vull = std::vector<unsigned long long>;\n\n#ifdef\
    \ __SIZEOF_INT128__\n\nusing li = __int128;\nusing pli = std::pair<__int128, __int128>;\n\
    using vli = std::vector<__int128>;\n\nusing uli = unsigned __int128;\nusing puli\
    \ = std::pair<unsigned __int128, unsigned __int128>;\nusing vuli = std::vector<unsigned\
    \ __int128>;\n\n#endif\n\nusing ld = long double;\nusing pld = std::pair<long\
    \ double, long double>;\nusing vld = std::vector<long double>;\n\n\n#line 1 \"\
    library/numerical/trailing_zero_bits.hpp\"\n\n\n\n// Verification:\n//\n\n#line\
    \ 8 \"library/numerical/trailing_zero_bits.hpp\"\n\ntemplate<typename T> T trailing_zero_bits(T\
    \ element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\tT result = 0;\n\tfor(;\
    \ (element & 1) ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\t}\n\treturn result;\n\
    }\n\n\n#line 9 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\nnamespace primality\n{\n\ttemplate<typename T> T power(T base, T exponent,\
    \ const T& modulus)\n\t{\n\t\tbase %= modulus;\n\t\tT result = 1;\n\t\twhile(exponent)\n\
    \t\t{\n\t\t\tif(exponent & 1)\n\t\t\t{\n\t\t\t\tresult = static_cast<uli>(result)\
    \ * base % modulus;\n\t\t\t}\n\t\t\tbase = static_cast<uli>(base) * base % modulus;\n\
    \t\t\texponent >>= 1;\n\t\t}\n\t\treturn result;\n\t}\n\n\ttemplate<typename T>\
    \ bool miller_rabin(const T& n, const bool& checkBaseCases = true, const std::vector<T>&\
    \ A = { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 })\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tif(checkBaseCases)\n\t\t{\n\t\t\tif(n <= 1)\n\t\t\t{ return false; }\n\t\t\
    \tif(n <= 2)\n\t\t\t{ return true; }\n\t\t\tfor(const auto& a : { 2, 3, 5, 7,\
    \ 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,\
    \ 89, 97 })\n\t\t\t{\n\t\t\t\tif(a > n)\n\t\t\t\t{ break; }\n\t\t\t\tif(n == a)\n\
    \t\t\t\t{\n\t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\tif(n % a == 0)\n\t\t\t\t\
    { return false; }\n\t\t\t}\n\t\t}\n\t\tT bits = trailing_zero_bits(n - 1), d =\
    \ (n - 1) >> bits, negativeOne = n - 1;\n\t\tfor(const T& a : A)\n\t\t{\n\t\t\t\
    if(a % n)\n\t\t\t{\n\t\t\t\tT x = power(a, d, n), i = 0;\n\t\t\t\tif(x == 1 ||\
    \ x == negativeOne)\n\t\t\t\t{ continue; }\n\t\t\t\tfor(; x != 1 && x != negativeOne\
    \ && i < bits; ++i)\n\t\t\t\t{\n\t\t\t\t\tif(x == 1)\n\t\t\t\t\t{ return false;\
    \ }\n\t\t\t\t\tif(x == negativeOne)\n\t\t\t\t\t{ break; }\n\t\t\t\t\tx = static_cast<uli>(x)\
    \ * x % n;\n\t\t\t\t}\n\t\t\t\tif((i == bits) ^ (x == 1))\n\t\t\t\t{ return false;\
    \ }\n\t\t\t}\n\t\t}\n\t\treturn true;\n\t}\n\n}\n\n\n"
  code: "#ifndef MILLER_RABIN_PRIMALITY_TEST_HPP\n#define MILLER_RABIN_PRIMALITY_TEST_HPP\n\
    \n#include <type_traits>\n#include <vector>\n\n#include \"../../general/base.hpp\"\
    \n#include \"../trailing_zero_bits.hpp\"\n\nnamespace primality\n{\n\ttemplate<typename\
    \ T> T power(T base, T exponent, const T& modulus)\n\t{\n\t\tbase %= modulus;\n\
    \t\tT result = 1;\n\t\twhile(exponent)\n\t\t{\n\t\t\tif(exponent & 1)\n\t\t\t\
    {\n\t\t\t\tresult = static_cast<uli>(result) * base % modulus;\n\t\t\t}\n\t\t\t\
    base = static_cast<uli>(base) * base % modulus;\n\t\t\texponent >>= 1;\n\t\t}\n\
    \t\treturn result;\n\t}\n\n\ttemplate<typename T> bool miller_rabin(const T& n,\
    \ const bool& checkBaseCases = true, const std::vector<T>& A = { 2, 325, 9375,\
    \ 28178, 450775, 9780504, 1795265022 })\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tif(checkBaseCases)\n\t\t{\n\t\t\tif(n <= 1)\n\t\t\t{ return false; }\n\t\t\
    \tif(n <= 2)\n\t\t\t{ return true; }\n\t\t\tfor(const auto& a : { 2, 3, 5, 7,\
    \ 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83,\
    \ 89, 97 })\n\t\t\t{\n\t\t\t\tif(a > n)\n\t\t\t\t{ break; }\n\t\t\t\tif(n == a)\n\
    \t\t\t\t{\n\t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\tif(n % a == 0)\n\t\t\t\t\
    { return false; }\n\t\t\t}\n\t\t}\n\t\tT bits = trailing_zero_bits(n - 1), d =\
    \ (n - 1) >> bits, negativeOne = n - 1;\n\t\tfor(const T& a : A)\n\t\t{\n\t\t\t\
    if(a % n)\n\t\t\t{\n\t\t\t\tT x = power(a, d, n), i = 0;\n\t\t\t\tif(x == 1 ||\
    \ x == negativeOne)\n\t\t\t\t{ continue; }\n\t\t\t\tfor(; x != 1 && x != negativeOne\
    \ && i < bits; ++i)\n\t\t\t\t{\n\t\t\t\t\tif(x == 1)\n\t\t\t\t\t{ return false;\
    \ }\n\t\t\t\t\tif(x == negativeOne)\n\t\t\t\t\t{ break; }\n\t\t\t\t\tx = static_cast<uli>(x)\
    \ * x % n;\n\t\t\t\t}\n\t\t\t\tif((i == bits) ^ (x == 1))\n\t\t\t\t{ return false;\
    \ }\n\t\t\t}\n\t\t}\n\t\treturn true;\n\t}\n\n}\n\n#endif"
  dependsOn:
  - library/general/base.hpp
  - library/general/unused.hpp
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/primality/miller_rabin_primality_test.hpp
  requiredBy:
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/numerical/factors/pollards_rho_factorization.hpp
  timestamp: '2021-03-26 00:07:57-06:00'
  verificationStatus: LIBRARY_ALL_AC
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
