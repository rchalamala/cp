---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"library/general/prng.hpp\"\n\n\n\n#include <chrono>\n#include\
    \ <type_traits>\n#include <random>\n\ninline std::mt19937_64& get_rng()\n{\n\t\
    #ifdef LOCAL\n\tstatic std::mt19937_64 rng{};\n\t#else\n\tstatic std::mt19937_64\
    \ rng{static_cast<std::uint64_t>( std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \t#endif\n\treturn rng;\n}\n\ntemplate<typename T1, typename T2, std::enable_if_t<std::is_integral_v<T1>\
    \ && std::is_integral_v<T2>, bool> = true> typename std::common_type_t<T1, T2>\
    \ getUID(const T1& uLow, const T2& uHigh, std::mt19937_64& device = get_rng())\n\
    {\n\ttypename std::common_type_t<T1, T2> low{uLow}, high{uHigh};\n\treturn std::uniform_int_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(device);\n}\n\ntemplate<typename\
    \ T1, typename T2, std::enable_if_t<std::is_floating_point_v<T1> && std::is_floating_point_v<T2>,\
    \ bool> = true> typename std::common_type_t<T1, T2> getURD(const T1& uLow, const\
    \ T2& uHigh, std::mt19937_64& device = get_rng())\n{\n\ttypename std::common_type_t<T1,\
    \ T2> low{uLow}, high{uHigh};\n\treturn std::uniform_real_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(device);\n}\n\n\n"
  code: "#ifndef PRNG_HPP\n#define PRNG_HPP\n\n#include <chrono>\n#include <type_traits>\n\
    #include <random>\n\ninline std::mt19937_64& get_rng()\n{\n\t#ifdef LOCAL\n\t\
    static std::mt19937_64 rng{};\n\t#else\n\tstatic std::mt19937_64 rng{static_cast<std::uint64_t>(\
    \ std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count())};\n\
    \t#endif\n\treturn rng;\n}\n\ntemplate<typename T1, typename T2, std::enable_if_t<std::is_integral_v<T1>\
    \ && std::is_integral_v<T2>, bool> = true> typename std::common_type_t<T1, T2>\
    \ getUID(const T1& uLow, const T2& uHigh, std::mt19937_64& device = get_rng())\n\
    {\n\ttypename std::common_type_t<T1, T2> low{uLow}, high{uHigh};\n\treturn std::uniform_int_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(device);\n}\n\ntemplate<typename\
    \ T1, typename T2, std::enable_if_t<std::is_floating_point_v<T1> && std::is_floating_point_v<T2>,\
    \ bool> = true> typename std::common_type_t<T1, T2> getURD(const T1& uLow, const\
    \ T2& uHigh, std::mt19937_64& device = get_rng())\n{\n\ttypename std::common_type_t<T1,\
    \ T2> low{uLow}, high{uHigh};\n\treturn std::uniform_real_distribution<typename\
    \ std::common_type<T1, T2>::type>(low, high)(device);\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/prng.hpp
  requiredBy:
  - library/numerical/factors/pollards_rho_factorization.hpp
  - library/numerical/factors/optimized_rho_factorization.hpp
  timestamp: '2021-04-05 00:55:31-06:00'
  verificationStatus: LIBRARY_ALL_WA
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
