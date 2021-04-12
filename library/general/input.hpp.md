---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
  bundledCode: "#line 1 \"library/general/input.hpp\"\n\n\n\n#include <array>\n#include\
    \ <complex>\n#include <istream>\n#include <string>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<typename Argument, typename... Arguments> bool read(Argument&\
    \ first, Arguments& ... rest);\n\ntemplate<typename T, std::size_t N> bool read(std::array<T,\
    \ N>& elements);\n\ntemplate<typename T1, typename T2> bool read(std::pair<T1,\
    \ T2>& element);\n\ntemplate<typename T> bool read(T& element);\n\ntemplate<typename\
    \ T> bool read(std::complex<T>& element);\n\ntemplate<typename T> bool read(std::vector<T>&\
    \ elements);\n\ntemplate<typename Argument, typename... Arguments> bool read(Argument&\
    \ first, Arguments& ... rest)\n{\n\tbool result{true};\n\tresult &= read(first);\n\
    \tresult &= read(rest...);\n\treturn result;\n}\n\ntemplate<typename T, std::size_t\
    \ Size> bool read(std::array<T, Size>& elements)\n{\n\tbool result{true};\n\t\
    for(T& element : elements)\n\t{ result &= read(element); }\n\treturn result;\n\
    }\n\ntemplate<typename T1, typename T2> bool read(std::pair<T1, T2>& element)\
    \ { return read(element.first, element.second); }\n\ntemplate<typename T> bool\
    \ read(T& element) { return static_cast<bool>(std::cin >> element); }\n\ntemplate<typename\
    \ T> bool read(std::complex<T>& element)\n{\n\tbool result{true};\n\tT first,\
    \ second;\n\tresult &= read(first, second);\n\telement = std::complex<T>(first,\
    \ second);\n\treturn result;\n}\n\ntemplate<typename T> bool read(std::vector<T>&\
    \ elements)\n{\n\tbool result{true};\n\tfor(T& element : elements)\n\t{ result\
    \ &= read(element); }\n\treturn result;\n}\n\n\n"
  code: "#ifndef INPUT_HPP\n#define INPUT_HPP\n\n#include <array>\n#include <complex>\n\
    #include <istream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \ntemplate<typename Argument, typename... Arguments> bool read(Argument& first,\
    \ Arguments& ... rest);\n\ntemplate<typename T, std::size_t N> bool read(std::array<T,\
    \ N>& elements);\n\ntemplate<typename T1, typename T2> bool read(std::pair<T1,\
    \ T2>& element);\n\ntemplate<typename T> bool read(T& element);\n\ntemplate<typename\
    \ T> bool read(std::complex<T>& element);\n\ntemplate<typename T> bool read(std::vector<T>&\
    \ elements);\n\ntemplate<typename Argument, typename... Arguments> bool read(Argument&\
    \ first, Arguments& ... rest)\n{\n\tbool result{true};\n\tresult &= read(first);\n\
    \tresult &= read(rest...);\n\treturn result;\n}\n\ntemplate<typename T, std::size_t\
    \ Size> bool read(std::array<T, Size>& elements)\n{\n\tbool result{true};\n\t\
    for(T& element : elements)\n\t{ result &= read(element); }\n\treturn result;\n\
    }\n\ntemplate<typename T1, typename T2> bool read(std::pair<T1, T2>& element)\
    \ { return read(element.first, element.second); }\n\ntemplate<typename T> bool\
    \ read(T& element) { return static_cast<bool>(std::cin >> element); }\n\ntemplate<typename\
    \ T> bool read(std::complex<T>& element)\n{\n\tbool result{true};\n\tT first,\
    \ second;\n\tresult &= read(first, second);\n\telement = std::complex<T>(first,\
    \ second);\n\treturn result;\n}\n\ntemplate<typename T> bool read(std::vector<T>&\
    \ elements)\n{\n\tbool result{true};\n\tfor(T& element : elements)\n\t{ result\
    \ &= read(element); }\n\treturn result;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/input.hpp
  requiredBy: []
  timestamp: '2021-04-12 14:19:14-06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/input.hpp
layout: document
redirect_from:
- /library/library/general/input.hpp
- /library/library/general/input.hpp.html
title: library/general/input.hpp
---
