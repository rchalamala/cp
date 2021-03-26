---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/general/base.hpp
    title: library/general/base.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/base.hpp
    title: library/general/base.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/prng.hpp
    title: library/general/prng.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/unused.hpp
    title: library/general/unused.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/primality/miller_rabin_primality_test.hpp
    title: library/numerical/primality/miller_rabin_primality_test.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/steins_gcd.hpp
    title: library/numerical/steins_gcd.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/factors/pollards_rho_factorization.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\n#line\
    \ 1 \"library/general/base.hpp\"\n\n\n\n#include <cassert>\n#include <cctype>\n\
    #include <cerrno>\n#include <cfloat>\n#include <climits>\n#include <clocale>\n\
    #include <cmath>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <cwchar>\n#include <cwctype>\n\n#if __cplusplus >=\
    \ 201103L\n\n#include <cfenv>\n#include <cinttypes>\n#include <cstdint>\n#include\
    \ <cuchar>\n\n#endif\n\n#line 32 \"library/general/base.hpp\"\n#include <bitset>\n\
    #include <complex>\n#include <deque>\n#include <exception>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <set>\n\
    #include <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n\
    #include <string>\n#include <typeinfo>\n#include <utility>\n#include <valarray>\n\
    #line 63 \"library/general/base.hpp\"\n\n#if __cplusplus >= 201103L\n\n#include\
    \ <typeindex>\n#line 68 \"library/general/base.hpp\"\n#include <chrono>\n#include\
    \ <initializer_list>\n#include <tuple>\n#include <scoped_allocator>\n#include\
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
    library/general/prng.hpp\"\n\n\n\n#include <chrono>\n#include <random>\n\ninline\
    \ std::mt19937_64& getPRNG()\n{\n\tstatic std::mt19937_64 PRNG{static_cast<std::uint_fast64_t>(\
    \ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \treturn PRNG;\n}\n\ntemplate<typename T> T getUID(const T& low, const T& high)\n\
    {\n\treturn std::uniform_int_distribution<T>(low, high)(getPRNG());\n}\n\ntemplate<typename\
    \ T> T getURD(const T& low, const T& high)\n{\n\treturn std::uniform_real_distribution<T>(low,\
    \ high)(getPRNG());\n}\n\n\n#line 1 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\n\n\n#line 6 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
    \n\n#line 1 \"library/numerical/trailing_zero_bits.hpp\"\n\n\n\n// Verification:\n\
    //\n\n#line 8 \"library/numerical/trailing_zero_bits.hpp\"\n\ntemplate<typename\
    \ T> T trailing_zero_bits(T element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \tT result = 0;\n\tfor(; (element & 1) ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\
    \t}\n\treturn result;\n}\n\n\n#line 9 \"library/numerical/primality/miller_rabin_primality_test.hpp\"\
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
    \ }\n\t\t\t}\n\t\t}\n\t\treturn true;\n\t}\n\n}\n\n\n#line 1 \"library/numerical/steins_gcd.hpp\"\
    \n\n\n\n#line 7 \"library/numerical/steins_gcd.hpp\"\n\ntemplate<typename T1,\
    \ typename T2> constexpr typename std::common_type<T1, T2>::type steins_gcd(const\
    \ T1& u_x, const T2& u_y)\n{\n\tstatic_assert(std::is_integral_v<T1>);\n\tstatic_assert(std::is_integral_v<T2>);\n\
    \ttypename std::common_type<T1, T2>::type x{ u_x }, y{ u_y };\n\tif(x == 0)\n\t\
    {\n\t\treturn y;\n\t}\n\tif(y == 0)\n\t{\n\t\treturn x;\n\t}\n\ttypename std::common_type<T1,\
    \ T2>::type a{ trailing_zero_bits(x) }, b{ trailing_zero_bits(y) };\n\tx >>= a;\n\
    \ty >>= b;\n\twhile(true)\n\t{\n\t\tif(x < y)\n\t\t{\n\t\t\tstd::swap(x, y);\n\
    \t\t}\n\t\tx -= y;\n\t\tif(!x)\n\t\t{\n\t\t\treturn y << std::min(a, b);\n\t\t\
    }\n\t\tx >>= trailing_zero_bits(x);\n\t}\n}\n\n\n#line 12 \"library/numerical/factors/pollards_rho_factorization.hpp\"\
    \n\nnamespace factors\n{\n\ttemplate<typename T> T pollards_rho(const T& n)\n\t\
    {\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tassert(n >= 0);\n\t\tif((n &\
    \ 1) ^ 1)\n\t\t{ return 2; }\n\t\tif(primality::miller_rabin(n))\n\t\t{ return\
    \ n; }\n\t\tT c;\n\t\tauto f = [&n, &c](const T& x) -> T\n\t\t{ return (static_cast<uli>(x)\
    \ * x + c) % n; };\n\t\tfor(T x0 = getUID<T>(static_cast<T>(0), n - 1);; x0 =\
    \ getUID<T>(static_cast<T>(0), n - 1))\n\t\t{\n\t\t\tc = getUID<T>(static_cast<T>(0),\
    \ n - 1);\n\t\t\tT x = f(x0), y = f(x);\n\t\t\twhile(true)\n\t\t\t{\n\t\t\t\t\
    T divisor = steins_gcd(std::max(x, y) - std::min(x, y), n);\n\t\t\t\tif(divisor\
    \ == n)\n\t\t\t\t{ break; }\n\t\t\t\tif(divisor != 1)\n\t\t\t\t{ return divisor;\
    \ }\n\t\t\t\tx = f(x);\n\t\t\t\ty = f(f(y));\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ T> std::vector<T> pollards_rho_factorize(const T& n)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tassert(n >= 0);\n\t\tif(n <= 1)\n\t\t{ return {}; }\n\t\tT factor = pollards_rho<T>(n);\n\
    \t\tif(n == factor)\n\t\t{ return std::vector<T>{ n }; }\n\t\tstd::vector<T> original{\
    \ pollards_rho_factorize(factor) }, divided{ pollards_rho_factorize(n / factor)\
    \ };\n\t\toriginal.insert(original.end(), divided.begin(), divided.end());\n\t\
    \treturn original;\n\t}\n}\n\n\n"
  code: "#ifndef POLLARDS_RHO_FACTORIZATION_HPP\n#define POLLARDS_RHO_FACTORIZATION_HPP\n\
    \n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\n#include\
    \ \"../../general/base.hpp\"\n#include \"../../general/prng.hpp\"\n#include \"\
    ../primality/miller_rabin_primality_test.hpp\"\n#include \"../steins_gcd.hpp\"\
    \n\nnamespace factors\n{\n\ttemplate<typename T> T pollards_rho(const T& n)\n\t\
    {\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tassert(n >= 0);\n\t\tif((n &\
    \ 1) ^ 1)\n\t\t{ return 2; }\n\t\tif(primality::miller_rabin(n))\n\t\t{ return\
    \ n; }\n\t\tT c;\n\t\tauto f = [&n, &c](const T& x) -> T\n\t\t{ return (static_cast<uli>(x)\
    \ * x + c) % n; };\n\t\tfor(T x0 = getUID<T>(static_cast<T>(0), n - 1);; x0 =\
    \ getUID<T>(static_cast<T>(0), n - 1))\n\t\t{\n\t\t\tc = getUID<T>(static_cast<T>(0),\
    \ n - 1);\n\t\t\tT x = f(x0), y = f(x);\n\t\t\twhile(true)\n\t\t\t{\n\t\t\t\t\
    T divisor = steins_gcd(std::max(x, y) - std::min(x, y), n);\n\t\t\t\tif(divisor\
    \ == n)\n\t\t\t\t{ break; }\n\t\t\t\tif(divisor != 1)\n\t\t\t\t{ return divisor;\
    \ }\n\t\t\t\tx = f(x);\n\t\t\t\ty = f(f(y));\n\t\t\t}\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ T> std::vector<T> pollards_rho_factorize(const T& n)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tassert(n >= 0);\n\t\tif(n <= 1)\n\t\t{ return {}; }\n\t\tT factor = pollards_rho<T>(n);\n\
    \t\tif(n == factor)\n\t\t{ return std::vector<T>{ n }; }\n\t\tstd::vector<T> original{\
    \ pollards_rho_factorize(factor) }, divided{ pollards_rho_factorize(n / factor)\
    \ };\n\t\toriginal.insert(original.end(), divided.begin(), divided.end());\n\t\
    \treturn original;\n\t}\n}\n\n#endif"
  dependsOn:
  - library/general/base.hpp
  - library/general/unused.hpp
  - library/general/prng.hpp
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/general/base.hpp
  - library/numerical/trailing_zero_bits.hpp
  - library/numerical/steins_gcd.hpp
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: false
  path: library/numerical/factors/pollards_rho_factorization.hpp
  requiredBy: []
  timestamp: '2021-03-26 00:07:57-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
documentation_of: library/numerical/factors/pollards_rho_factorization.hpp
layout: document
redirect_from:
- /library/library/numerical/factors/pollards_rho_factorization.hpp
- /library/library/numerical/factors/pollards_rho_factorization.hpp.html
title: library/numerical/factors/pollards_rho_factorization.hpp
---
