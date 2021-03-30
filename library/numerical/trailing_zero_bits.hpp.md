---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/trailing_zero_bits.hpp\"\n\n\n\n#include\
    \ <cstdint>\n#include <type_traits>\n\ntemplate<typename T> std::uint64_t trailing_zero_bits(const\
    \ T& element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\treturn __builtin_ctzll(element);\n\
    }\n\n/*\ntemplate<typename T> T trailing_zero_bits(T element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \tstatic_assert(std::is_unsigned_v<T>);\n\tT result{};\n\tfor(; (element & 1)\
    \ ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\t}\n\treturn result;\n}\n*/\n\n\n"
  code: "#ifndef TRAILING_ZERO_BITS_HPP\n#define TRAILING_ZERO_BITS_HPP\n\n#include\
    \ <cstdint>\n#include <type_traits>\n\ntemplate<typename T> std::uint64_t trailing_zero_bits(const\
    \ T& element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\treturn __builtin_ctzll(element);\n\
    }\n\n/*\ntemplate<typename T> T trailing_zero_bits(T element)\n{\n\tstatic_assert(std::is_integral_v<T>);\n\
    \tstatic_assert(std::is_unsigned_v<T>);\n\tT result{};\n\tfor(; (element & 1)\
    \ ^ 1; ++result)\n\t{\n\t\telement >>= 1;\n\t}\n\treturn result;\n}\n*/\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/trailing_zero_bits.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/trailing_zero_bits.hpp
layout: document
redirect_from:
- /library/library/numerical/trailing_zero_bits.hpp
- /library/library/numerical/trailing_zero_bits.hpp.html
title: library/numerical/trailing_zero_bits.hpp
---
