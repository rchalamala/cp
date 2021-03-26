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
    path: library/general/input.hpp
    title: library/general/input.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/output.hpp
    title: library/general/output.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/prng.hpp
    title: library/general/prng.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/speed.hpp
    title: library/general/speed.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/to_string.hpp
    title: library/general/to_string.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/unused.hpp
    title: library/general/unused.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/factors/optimized_rho_factorization.hpp
    title: library/numerical/factors/optimized_rho_factorization.hpp
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
  - icon: ':heavy_check_mark:'
    path: library/numerical/trailing_zero_bits.hpp
    title: library/numerical/trailing_zero_bits.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"library/general/input.hpp\"\n\n\n\n// Verification:\n//\n\
    #include <array>\n#include <complex>\n#include <istream>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\ninline bool read(std::istream& in, double& element);\n\
    \ninline bool read(std::istream& in, long double& element);\n\ntemplate<typename\
    \ Argument, typename... Arguments> bool read(std::istream& in, Argument& first,\
    \ Arguments& ... rest);\n\ntemplate<typename T, std::size_t Size> bool read(std::istream&\
    \ in, std::array<T, Size>& elements);\n\ntemplate<typename T1, typename T2> bool\
    \ read(std::istream& in, std::pair<T1, T2>& element);\n\ntemplate<typename T>\
    \ bool read(std::istream& in, T& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::complex<T>& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::tuple<T, T, T, T, T, T>& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::tuple<T, T, T, T, T>& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::tuple<T, T, T, T>& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::tuple<T, T, T>& element);\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::vector<T>& elements);\n\ninline bool read(std::istream& in, double&\
    \ element)\n{\n\tbool result = true;\n\tstd::string convert;\n\tresult &= read(in,\
    \ convert);\n\telement = std::stod(convert);\n\treturn result;\n}\n\ninline bool\
    \ read(std::istream& in, long double& element)\n{\n\tbool result = true;\n\tstd::string\
    \ convert;\n\tresult &= read(in, convert);\n\telement = std::stold(convert);\n\
    \treturn result;\n}\n\ntemplate<typename Argument, typename... Arguments> bool\
    \ read(std::istream& in, Argument& first, Arguments& ... rest)\n{\n\tbool result\
    \ = true;\n\tresult &= read(in, first);\n\tresult &= read(in, rest...);\n\treturn\
    \ result;\n}\n\ntemplate<typename T, std::size_t Size> bool read(std::istream&\
    \ in, std::array<T, Size>& elements)\n{\n\tbool result = true;\n\tfor(T& element\
    \ : elements)\n\t{ result &= read(in, element); }\n\treturn result;\n}\n\ntemplate<typename\
    \ T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element)\n{\n\
    \treturn read(in, element.first, element.second);\n}\n\ntemplate<typename T> bool\
    \ read(std::istream& in, T& element)\n{\n\treturn static_cast<bool>(in >> element);\n\
    }\n\ntemplate<typename T> bool read(std::istream& in, std::complex<T>& element)\n\
    {\n\tbool result = true;\n\tT first, second;\n\tresult &= read(in, first, second);\n\
    \telement = std::complex<T>(first, second);\n\treturn result;\n}\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element)\n{\n\t\
    return read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element),\
    \ std::get<3>(element), std::get<4>(element), std::get<5>(element));\n}\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::tuple<T, T, T, T, T>& element)\n{\n\treturn\
    \ read(in, std::get<0>(element), std::get<1>(element), std::get<2>(element), std::get<3>(element),\
    \ std::get<4>(element));\n}\n\ntemplate<typename T> bool read(std::istream& in,\
    \ std::tuple<T, T, T, T>& element)\n{\n\treturn read(in, std::get<0>(element),\
    \ std::get<1>(element), std::get<2>(element), std::get<3>(element));\n}\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::tuple<T, T, T>& element)\n{\n\treturn read(in,\
    \ std::get<0>(element), std::get<1>(element), std::get<2>(element));\n}\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::vector<T>& elements)\n{\n\tbool result =\
    \ true;\n\tfor(T& element : elements)\n\t{ result &= read(in, element); }\n\t\
    return result;\n}\n\n\n#line 1 \"library/general/output.hpp\"\n\n\n\n// Verification:\n\
    //\n#line 1 \"library/general/to_string.hpp\"\n\n\n\n#include <bitset>\n#line\
    \ 6 \"library/general/to_string.hpp\"\n#include <string>\n#line 9 \"library/general/to_string.hpp\"\
    \n\nnamespace std\n{\n\tinline std::string to_string(const bool& element);\n\n\
    \tinline std::string to_string(const char& element);\n\n\tinline std::string to_string(const\
    \ char* element);\n\n\tinline std::string to_string(const std::string& element);\n\
    \n\tinline std::string to_string(const std::vector<bool>& elements);\n\n\ttemplate<typename\
    \ T> std::string to_string(const T& elements);\n\n\ttemplate<std::size_t Size>\
    \ std::string to_string(const std::bitset<Size>& elements);\n\n\ttemplate<typename\
    \ T> std::string to_string(const std::complex<T>& element);\n\n\ttemplate<typename\
    \ T1, typename T2> std::string to_string(std::pair<T1, T2> element);\n}  // namespace\
    \ std\n\ninline std::string std::to_string(const bool& element)\n{\n#ifdef LOCAL\n\
    \treturn element ? \"true\" : \"false\";\n#else\n\treturn std::string{static_cast<char>('0'\
    \ + element)};\n#endif\n}\n\ninline std::string std::to_string(const char& element)\n\
    {\n\treturn std::string(1, element);\n}\n\ninline std::string std::to_string(const\
    \ char* element)\n{\n\treturn std::string(element);\n}\n\ninline std::string std::to_string(const\
    \ std::string& element)\n{\n\treturn element;\n}\n\ninline std::string std::to_string(const\
    \ std::vector<bool>& elements)\n{\n\tstd::string convert = \"{\";\n\tfor(const\
    \ auto&& element : elements)\n\t{\n\t\tconvert += static_cast<char>('0' + element);\n\
    \t}\n\treturn convert + \"}\";\n}\n\ntemplate<typename T> std::string std::to_string(const\
    \ T& elements)\n{\n\tstd::string convert;\n\tbool first = true;\n#ifdef LOCAL\n\
    \tconvert += \"{\";\n\tfor(const auto& element : elements)\n\t{\n\t\tif(!first)\n\
    \t\t{ convert += \", \"; }\n\t\tfirst = false;\n\t\tconvert += std::to_string(element);\n\
    \t}\n\tconvert += \"}\";\n#else\n\tfor(const auto& element : elements)\n\t{\n\t\
    \tif(!first) convert += \" \";\n\t\tfirst = false;\n\t\tconvert += std::to_string(element);\n\
    \t}\n#endif\n\treturn convert;\n}\n\ntemplate<std::size_t Size> std::string std::to_string(const\
    \ std::bitset<Size>& elements)\n{\n\treturn elements.to_string();\n}\n\ntemplate<typename\
    \ T> std::string std::to_string(const std::complex<T>& element)\n{\n\tstd::stringstream\
    \ convert;\n\tconvert << element;\n\treturn convert.str();\n}\n\ntemplate<typename\
    \ T1, typename T2> std::string std::to_string(std::pair<T1, T2> element)\n{\n\
    #ifdef LOCAL\n\treturn \"(\" + std::to_string(element.first) + \", \" + std::to_string(element.second)\
    \ + \")\";\n#else\n\treturn std::to_string(element.ff) + \" \" + std::to_string(element.ss);\n\
    #endif\n}\n\n\n#line 7 \"library/general/output.hpp\"\n#include <ostream>\n\n\
    template<typename Argument, typename... Arguments> void print(std::ostream& out,\
    \ const Argument& first, const Arguments& ... rest);\n\ntemplate<typename Argument,\
    \ typename... Arguments> void printn(std::ostream& out, const Argument& first,\
    \ const Arguments& ... rest);\n\ntemplate<typename Argument, typename... Arguments>\
    \ void prints(std::ostream& out, const Argument& first, const Arguments& ... rest);\n\
    \ntemplate<typename T> void print(std::ostream& out, const T& element);\n\ninline\
    \ void printn(std::ostream& out);\n\ninline void prints(std::ostream& out);\n\n\
    template<typename T> void print(std::ostream& out, const T& element)\n{\n\tout\
    \ << std::to_string(element);\n}\n\ninline void printn(std::ostream& out)\n{\n\
    \tprint(out, '\\n');\n}\n\ninline void prints(std::ostream& out)\n{\n\tprint(out,\
    \ '\\n');\n}\n\ntemplate<typename Argument, typename... Arguments> void print(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\
    \tprint(out, rest...);\n}\n\ntemplate<typename Argument, typename... Arguments>\
    \ void printn(std::ostream& out, const Argument& first, const Arguments& ... rest)\n\
    {\n\tprint(out, first);\n\tif(sizeof...(rest))\n\t{ prints(out); }\n\tprintn(out,\
    \ rest...);\n}\n\ntemplate<typename Argument, typename... Arguments> void prints(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\
    \tif(sizeof...(rest))\n\t{ print(out, \" \"); }\n\tprints(out, rest...);\n}\n\n\
    \n#line 1 \"library/general/speed.hpp\"\n\n\n\n#include <iostream>\n\ninline bool\
    \ speed()\n{\n\tstd::cin.exceptions(std::cin.failbit);\n\treturn std::cin.tie(nullptr)\
    \ && std::ios_base::sync_with_stdio(false);\n}\n\n\n#line 4 \"verification/numerical/factors/optimized_rho_factorization.test.cpp\"\
    \n\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ <algorithm>\n#include <cstdint>\n#line 11 \"verification/numerical/factors/optimized_rho_factorization.test.cpp\"\
    \n\n#line 1 \"library/numerical/factors/optimized_rho_factorization.hpp\"\n\n\n\
    \n#include <type_traits>\n#line 6 \"library/numerical/factors/optimized_rho_factorization.hpp\"\
    \n\n#line 1 \"library/general/base.hpp\"\n\n\n\n#include <cassert>\n#include <cctype>\n\
    #include <cerrno>\n#include <cfloat>\n#include <climits>\n#include <clocale>\n\
    #include <cmath>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n\
    #include <ctime>\n#include <cwchar>\n#include <cwctype>\n\n#if __cplusplus >=\
    \ 201103L\n\n#include <cfenv>\n#include <cinttypes>\n#line 27 \"library/general/base.hpp\"\
    \n#include <cuchar>\n\n#endif\n\n#line 34 \"library/general/base.hpp\"\n#include\
    \ <deque>\n#include <exception>\n#include <fstream>\n#include <functional>\n#include\
    \ <iomanip>\n#include <ios>\n#include <iosfwd>\n#line 43 \"library/general/base.hpp\"\
    \n#include <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n\
    #include <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#line 52\
    \ \"library/general/base.hpp\"\n#include <queue>\n#include <set>\n#include <sstream>\n\
    #include <stack>\n#include <stdexcept>\n#include <streambuf>\n#line 59 \"library/general/base.hpp\"\
    \n#include <typeinfo>\n#line 61 \"library/general/base.hpp\"\n#include <valarray>\n\
    #line 63 \"library/general/base.hpp\"\n\n#if __cplusplus >= 201103L\n\n#include\
    \ <typeindex>\n#line 68 \"library/general/base.hpp\"\n#include <chrono>\n#include\
    \ <initializer_list>\n#line 71 \"library/general/base.hpp\"\n#include <scoped_allocator>\n\
    #line 73 \"library/general/base.hpp\"\n#include <cinttypes>\n#include <system_error>\n\
    #include <cuchar>\n#line 77 \"library/general/base.hpp\"\n#include <forward_list>\n\
    #include <unordered_set>\n#include <unordered_map>\n#include <random>\n#include\
    \ <ratio>\n#include <cfenv>\n#include <regex>\n#include <atomic>\n#include <thread>\n\
    #include <mutex>\n#include <future>\n#include <condition_variable>\n\n#endif\n\
    \n#if __cplusplus >= 201402L\n\n#include <shared_mutex>\n\n#endif\n\n#if __cplusplus\
    \ >= 201703L\n\n#include <any>\n#include <charconv>\n//#include <execution>\n\
    #include <filesystem>\n#include <memory_resource>\n#include <optional>\n#include\
    \ <string_view>\n#include <variant>\n\n#endif\n\n#if __cplusplus >= 202002L\n\
    #include <barrier>\n#include <bit>\n#include <compare>\n#include <concepts>\n\
    #include <coroutine>\n#include <format>\n#include <latch>\n#include <numbers>\n\
    #include <ranges>\n#include <semaphore>\n#include <source_location>\n#include\
    \ <span>\n#include <stop_token>\n#include <syncstream>\n#include <version>\n#endif\n\
    \n#ifdef __GNUC__\n\n#include <ext/pb_ds/assoc_container.hpp>\n#include <ext/pb_ds/tree_policy.hpp>\n\
    #include <ext/rope>\n\nusing namespace __gnu_pbds;\nusing namespace __gnu_cxx;\n\
    \ntemplate<typename T> using ordered_set = __gnu_pbds::tree<T, __gnu_pbds::null_type,\
    \ std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;\n\
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
    }\n\t\tx >>= trailing_zero_bits(x);\n\t}\n}\n\n\n#line 12 \"library/numerical/factors/optimized_rho_factorization.hpp\"\
    \n\nnamespace factors\n{\n\ttemplate<typename T> T optimized_rho(const T& n)\n\
    \t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tassert(n >= 0);\n\t\tif(primality::miller_rabin(n,\
    \ true))\n\t\t{ return n; }\n\t\tT c;\n\t\tauto f = [&n, &c](const T& x) -> T\n\
    \t\t{ return (static_cast<uli>(x) * x + c) % n; };\n\t\tfor(T x0 = getUID<T>(static_cast<T>(0),\
    \ n - 1);; x0 = getUID<T>(static_cast<T>(0), n - 1))\n\t\t{\n\t\t\tc = getUID<T>(static_cast<T>(0),\
    \ n - 1);\n\t\t\tT product = 1;\n\t\t\tfor(T x = f(x0), y = f(x), trials = 30;\
    \ x != y && (trials % 40 || steins_gcd(product, n) == 1); x = f(x), y = f(f(y)))\n\
    \t\t\t{\n\t\t\t\tT combined = static_cast<uli>(product) * (n + x - y) % n;\n\t\
    \t\t\tif(combined)\n\t\t\t\t{ ++trials, product = combined; }\n\t\t\t}\n\t\t\t\
    T factor = steins_gcd(product, n);\n\t\t\tif(factor != 1 && factor != n)\n\t\t\
    \t{ return factor; }\n\t\t}\n\t}\n\n\ttemplate<typename T> std::vector<T> optimized_rho_factorize(const\
    \ T& n, const bool& checkBaseCases = true)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tassert(n >= 0);\n\t\tif(n <= 1)\n\t\t{ return {}; }\n\t\tif(checkBaseCases)\n\
    \t\t{\n\t\t\tT start = n;\n\t\t\tstd::vector<T> original{};\n\t\t\tfor(const auto&\
    \ a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,\
    \ 71, 73, 79, 83, 89, 97 })\n\t\t\t{\n\t\t\t\tif(a > start)\n\t\t\t\t{ break;\
    \ }\n\t\t\t\twhile(start % a == 0)\n\t\t\t\t{\n\t\t\t\t\toriginal.push_back(a);\n\
    \t\t\t\t\tstart /= a;\n\t\t\t\t}\n\t\t\t}\n\t\t\tstd::vector<T> divided{ optimized_rho_factorize(start,\
    \ false) };\n\t\t\toriginal.insert(original.end(), divided.begin(), divided.end());\n\
    \t\t\treturn original;\n\t\t}\n\t\tT factor = optimized_rho<T>(n);\n\t\tif(n ==\
    \ factor)\n\t\t{ return std::vector<T>{ n }; }\n\t\tstd::vector<T> original{ optimized_rho_factorize(factor,\
    \ false) }, divided{ optimized_rho_factorize(n / factor, false) };\n\t\toriginal.insert(original.end(),\
    \ divided.begin(), divided.end());\n\t\treturn original;\n\t}\n}\n\n\n#line 13\
    \ \"verification/numerical/factors/optimized_rho_factorization.test.cpp\"\n\n\
    int main()\n{\n\tspeed();\n\tstd::int_fast16_t q;\n\tread(std::cin, q);\n\twhile(q--)\n\
    \t{\n\t\tstd::int_fast64_t a;\n\t\tread(std::cin, a);\n\t\tstd::vector<std::int_fast64_t>\
    \ factors = factors::optimized_rho_factorize<std::int_fast64_t>(a);\n\t\tstd::sort(std::begin(factors),\
    \ std::end(factors));\n\t\tprints(std::cout, std::size(factors), factors);\n\t\
    }\n}\n"
  code: "#include \"../../../library/general/input.hpp\"\n#include \"../../../library/general/output.hpp\"\
    \n#include \"../../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#include <algorithm>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../../library/numerical/factors/optimized_rho_factorization.hpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::int_fast16_t q;\n\tread(std::cin, q);\n\t\
    while(q--)\n\t{\n\t\tstd::int_fast64_t a;\n\t\tread(std::cin, a);\n\t\tstd::vector<std::int_fast64_t>\
    \ factors = factors::optimized_rho_factorize<std::int_fast64_t>(a);\n\t\tstd::sort(std::begin(factors),\
    \ std::end(factors));\n\t\tprints(std::cout, std::size(factors), factors);\n\t\
    }\n}\n"
  dependsOn:
  - library/general/input.hpp
  - library/general/output.hpp
  - library/general/to_string.hpp
  - library/general/speed.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  - library/general/base.hpp
  - library/general/unused.hpp
  - library/general/prng.hpp
  - library/numerical/primality/miller_rabin_primality_test.hpp
  - library/general/base.hpp
  - library/numerical/trailing_zero_bits.hpp
  - library/numerical/steins_gcd.hpp
  - library/numerical/trailing_zero_bits.hpp
  - library/numerical/trailing_zero_bits.hpp
  isVerificationFile: true
  path: verification/numerical/factors/optimized_rho_factorization.test.cpp
  requiredBy: []
  timestamp: '2021-03-26 00:07:57-06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verification/numerical/factors/optimized_rho_factorization.test.cpp
layout: document
redirect_from:
- /verify/verification/numerical/factors/optimized_rho_factorization.test.cpp
- /verify/verification/numerical/factors/optimized_rho_factorization.test.cpp.html
title: verification/numerical/factors/optimized_rho_factorization.test.cpp
---
