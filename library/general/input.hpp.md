---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
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
  bundledCode: "#line 1 \"library/general/input.hpp\"\n\n\n\n// Verification:\n//\n\
    #include <array>\n#include <complex>\n#include <istream>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\ninline bool read(std::istream& in, double& element);\n\
    \ninline bool read(std::istream& in, long double& element);\n\ntemplate <typename\
    \ Argument, typename... Arguments>\nbool read(std::istream& in, Argument& first,\
    \ Arguments&... rest);\n\ntemplate <typename T, std::size_t Size>\nbool read(std::istream&\
    \ in, std::array<T, Size>& elements);\n\ntemplate <typename T1, typename T2>\n\
    bool read(std::istream& in, std::pair<T1, T2>& element);\n\ntemplate <typename\
    \ T>\nbool read(std::istream& in, T& element);\n\ntemplate <typename T>\nbool\
    \ read(std::istream& in, std::complex<T>& element);\n\ntemplate <typename T>\n\
    bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);\n\ntemplate\
    \ <typename T>\nbool read(std::istream& in, std::tuple<T, T, T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::vector<T>& elements);\n\
    \ninline bool read(std::istream& in, double& element) {\n\tbool result = true;\n\
    \tstd::string convert;\n\tresult &= read(in, convert);\n\telement = std::stod(convert);\n\
    \treturn result;\n}\n\ninline bool read(std::istream& in, long double& element)\
    \ {\n\tbool result = true;\n\tstd::string convert;\n\tresult &= read(in, convert);\n\
    \telement = std::stold(convert);\n\treturn result;\n}\n\ntemplate <typename Argument,\
    \ typename... Arguments>\nbool read(std::istream& in, Argument& first, Arguments&...\
    \ rest) {\n\tbool result = true;\n\tresult &= read(in, first);\n\tresult &= read(in,\
    \ rest...);\n\treturn result;\n}\n\ntemplate <typename T, std::size_t Size>\n\
    bool read(std::istream& in, std::array<T, Size>& elements) {\n\tbool result =\
    \ true;\n\tfor (T& element : elements) result &= read(in, element);\n\treturn\
    \ result;\n}\n\ntemplate <typename T1, typename T2>\nbool read(std::istream& in,\
    \ std::pair<T1, T2>& element) {\n\treturn read(in, element.first, element.second);\n\
    }\n\ntemplate <typename T>\nbool read(std::istream& in, T& element) {\n\treturn\
    \ static_cast<bool>(in >> element);\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::complex<T>& element) {\n\tbool result = true;\n\tT first, second;\n\
    \tresult &= read(in, first, second);\n\telement = std::complex<T>(first, second);\n\
    \treturn result;\n}\n\ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T,\
    \ T, T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element), std::get<1>(element),\n\
    \t            std::get<2>(element), std::get<3>(element), std::get<4>(element),\n\
    \t            std::get<5>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::tuple<T, T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element),\
    \ std::get<1>(element),\n\t            std::get<2>(element), std::get<3>(element),\
    \ std::get<4>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::tuple<T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element),\
    \ std::get<1>(element),\n\t            std::get<2>(element), std::get<3>(element));\n\
    }\n\ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T>& element)\
    \ {\n\treturn read(in, std::get<0>(element), std::get<1>(element),\n\t       \
    \     std::get<2>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::vector<T>& elements) {\n\tbool result = true;\n\tfor (T& element :\
    \ elements) result &= read(in, element);\n\treturn result;\n}\n\n\n"
  code: "#ifndef INPUT_HPP\n#define INPUT_HPP\n\n// Verification:\n//\n#include <array>\n\
    #include <complex>\n#include <istream>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\ninline bool read(std::istream& in, double& element);\n\n\
    inline bool read(std::istream& in, long double& element);\n\ntemplate <typename\
    \ Argument, typename... Arguments>\nbool read(std::istream& in, Argument& first,\
    \ Arguments&... rest);\n\ntemplate <typename T, std::size_t Size>\nbool read(std::istream&\
    \ in, std::array<T, Size>& elements);\n\ntemplate <typename T1, typename T2>\n\
    bool read(std::istream& in, std::pair<T1, T2>& element);\n\ntemplate <typename\
    \ T>\nbool read(std::istream& in, T& element);\n\ntemplate <typename T>\nbool\
    \ read(std::istream& in, std::complex<T>& element);\n\ntemplate <typename T>\n\
    bool read(std::istream& in, std::tuple<T, T, T, T, T, T>& element);\n\ntemplate\
    \ <typename T>\nbool read(std::istream& in, std::tuple<T, T, T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T>& element);\n\
    \ntemplate <typename T>\nbool read(std::istream& in, std::vector<T>& elements);\n\
    \ninline bool read(std::istream& in, double& element) {\n\tbool result = true;\n\
    \tstd::string convert;\n\tresult &= read(in, convert);\n\telement = std::stod(convert);\n\
    \treturn result;\n}\n\ninline bool read(std::istream& in, long double& element)\
    \ {\n\tbool result = true;\n\tstd::string convert;\n\tresult &= read(in, convert);\n\
    \telement = std::stold(convert);\n\treturn result;\n}\n\ntemplate <typename Argument,\
    \ typename... Arguments>\nbool read(std::istream& in, Argument& first, Arguments&...\
    \ rest) {\n\tbool result = true;\n\tresult &= read(in, first);\n\tresult &= read(in,\
    \ rest...);\n\treturn result;\n}\n\ntemplate <typename T, std::size_t Size>\n\
    bool read(std::istream& in, std::array<T, Size>& elements) {\n\tbool result =\
    \ true;\n\tfor (T& element : elements) result &= read(in, element);\n\treturn\
    \ result;\n}\n\ntemplate <typename T1, typename T2>\nbool read(std::istream& in,\
    \ std::pair<T1, T2>& element) {\n\treturn read(in, element.first, element.second);\n\
    }\n\ntemplate <typename T>\nbool read(std::istream& in, T& element) {\n\treturn\
    \ static_cast<bool>(in >> element);\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::complex<T>& element) {\n\tbool result = true;\n\tT first, second;\n\
    \tresult &= read(in, first, second);\n\telement = std::complex<T>(first, second);\n\
    \treturn result;\n}\n\ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T,\
    \ T, T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element), std::get<1>(element),\n\
    \t            std::get<2>(element), std::get<3>(element), std::get<4>(element),\n\
    \t            std::get<5>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::tuple<T, T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element),\
    \ std::get<1>(element),\n\t            std::get<2>(element), std::get<3>(element),\
    \ std::get<4>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::tuple<T, T, T, T>& element) {\n\treturn read(in, std::get<0>(element),\
    \ std::get<1>(element),\n\t            std::get<2>(element), std::get<3>(element));\n\
    }\n\ntemplate <typename T>\nbool read(std::istream& in, std::tuple<T, T, T>& element)\
    \ {\n\treturn read(in, std::get<0>(element), std::get<1>(element),\n\t       \
    \     std::get<2>(element));\n}\n\ntemplate <typename T>\nbool read(std::istream&\
    \ in, std::vector<T>& elements) {\n\tbool result = true;\n\tfor (T& element :\
    \ elements) result &= read(in, element);\n\treturn result;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/input.hpp
  requiredBy: []
  timestamp: '2021-03-25 17:49:28-06:00'
  verificationStatus: LIBRARY_ALL_AC
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
