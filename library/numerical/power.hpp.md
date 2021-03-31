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
  bundledCode: "#line 1 \"library/numerical/power.hpp\"\n\n\n\n#include <type_traits>\n\
    \ntemplate<typename T1, typename T2> constexpr typename std::enable_if_t<(std::is_integral_v<T1>\
    \ && std::is_unsigned_v<T1> && std::is_integral_v<T2> && std::is_unsigned_v<T2>),\
    \ typename std::common_type_t<T1, T2>> power(T1 base, T2 exponent)\n{\n\ttypename\
    \ std::common_type_t<T1, T2> result{1};\n\twhile(exponent)\n\t{\n\t\tif(exponent\
    \ & 1)\n\t\t{ result *= base; }\n\t\tbase *= base;\n\t\texponent >>= 1;\n\t}\n\
    \treturn result;\n}\n\ntemplate<typename T1, typename T2> constexpr typename std::enable_if_t<std::is_integral_v<T1>\
    \ && std::is_integral_v<T2> && (std::is_signed_v<T1> || std::is_signed_v<T2>),\
    \ typename std::common_type_t<T1, T2>> power(T1 base, T2 exponent)\n{\n\tassert(exponent\
    \ >= 0);\n\ttypename std::common_type_t<T1, T2> result{1};\n\twhile(exponent)\n\
    \t{\n\t\tif(exponent % 2)\n\t\t{ result *= base; }\n\t\tbase *= base;\n\t\texponent\
    \ /= 2;\n\t}\n\treturn result;\n}\n\n\n"
  code: "#ifndef POWER_HPP\n#define POWER_HPP\n\n#include <type_traits>\n\ntemplate<typename\
    \ T1, typename T2> constexpr typename std::enable_if_t<(std::is_integral_v<T1>\
    \ && std::is_unsigned_v<T1> && std::is_integral_v<T2> && std::is_unsigned_v<T2>),\
    \ typename std::common_type_t<T1, T2>> power(T1 base, T2 exponent)\n{\n\ttypename\
    \ std::common_type_t<T1, T2> result{1};\n\twhile(exponent)\n\t{\n\t\tif(exponent\
    \ & 1)\n\t\t{ result *= base; }\n\t\tbase *= base;\n\t\texponent >>= 1;\n\t}\n\
    \treturn result;\n}\n\ntemplate<typename T1, typename T2> constexpr typename std::enable_if_t<std::is_integral_v<T1>\
    \ && std::is_integral_v<T2> && (std::is_signed_v<T1> || std::is_signed_v<T2>),\
    \ typename std::common_type_t<T1, T2>> power(T1 base, T2 exponent)\n{\n\tassert(exponent\
    \ >= 0);\n\ttypename std::common_type_t<T1, T2> result{1};\n\twhile(exponent)\n\
    \t{\n\t\tif(exponent % 2)\n\t\t{ result *= base; }\n\t\tbase *= base;\n\t\texponent\
    \ /= 2;\n\t}\n\treturn result;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/power.hpp
  requiredBy: []
  timestamp: '2021-03-30 13:00:21-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/power.hpp
layout: document
redirect_from:
- /library/library/numerical/power.hpp
- /library/library/numerical/power.hpp.html
title: library/numerical/power.hpp
---
