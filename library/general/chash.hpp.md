---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://xorshift.di.unimi.it/splitmix64.c
  bundledCode: "#line 1 \"library/general/chash.hpp\"\n\n\n\n// http://xorshift.di.unimi.it/splitmix64.c\n\
    \n#include <chrono>\n#include <cstdint>\n#include <utility>\n\nstruct chash\n\
    {\n\tstatic std::uint64_t splitmix64(std::uint64_t x)\n\t{\n\t\tx += 0x9e3779b97f4a7c15;\n\
    \t\t(x ^= (x >> static_cast<std::uint64_t>(30))) *= 0xbf58476d1ce4e5b9;\n\t\t\
    (x ^= (x >> static_cast<std::uint64_t>(27))) *= 0x94d049bb133111eb;\n\t\treturn\
    \ x ^ (x >> static_cast<std::uint64_t>(31));\n\t}\n\n\tstd::size_t operator()(const\
    \ std::uint64_t x) const\n\t{\n\t\tstatic const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n\n\tstd::size_t operator()(const\
    \ std::pair<std::uint64_t, std::uint64_t> x) const\n\t{\n\t\tstatic const std::uint64_t\
    \ FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\treturn splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM)\
    \ >> static_cast<std::uint64_t>(1));\n\t}\n};\n\n\n"
  code: "#ifndef CHASH_HPP\n#define CHASH_HPP\n\n// http://xorshift.di.unimi.it/splitmix64.c\n\
    \n#include <chrono>\n#include <cstdint>\n#include <utility>\n\nstruct chash\n\
    {\n\tstatic std::uint64_t splitmix64(std::uint64_t x)\n\t{\n\t\tx += 0x9e3779b97f4a7c15;\n\
    \t\t(x ^= (x >> static_cast<std::uint64_t>(30))) *= 0xbf58476d1ce4e5b9;\n\t\t\
    (x ^= (x >> static_cast<std::uint64_t>(27))) *= 0x94d049bb133111eb;\n\t\treturn\
    \ x ^ (x >> static_cast<std::uint64_t>(31));\n\t}\n\n\tstd::size_t operator()(const\
    \ std::uint64_t x) const\n\t{\n\t\tstatic const std::uint64_t FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\treturn splitmix64(x + FIXED_RANDOM);\n\t}\n\n\tstd::size_t operator()(const\
    \ std::pair<std::uint64_t, std::uint64_t> x) const\n\t{\n\t\tstatic const std::uint64_t\
    \ FIXED_RANDOM = static_cast<std::uint64_t>(std::chrono::steady_clock::now().time_since_epoch().count());\n\
    \t\treturn splitmix64(x.first + FIXED_RANDOM) ^ (splitmix64(x.second + FIXED_RANDOM)\
    \ >> static_cast<std::uint64_t>(1));\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/chash.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/chash.hpp
layout: document
redirect_from:
- /library/library/general/chash.hpp
- /library/library/general/chash.hpp.html
title: library/general/chash.hpp
---
