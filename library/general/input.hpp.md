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
  bundledCode: "#line 1 \"library/general/input.hpp\"\n\n\n\n#include <array>\n#include\
    \ <complex>\n#include <istream>\n#include <string>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<typename Argument, typename... Arguments> bool read(std::istream&\
    \ in, Argument& first, Arguments& ... rest);\n\ntemplate<typename T, std::size_t\
    \ N> bool read(std::istream& in, std::array<T, N>& elements);\n\ntemplate<typename\
    \ T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element);\n\n\
    template<typename T> bool read(std::istream& in, T& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::complex<T>& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::vector<T>& elements);\n\ntemplate<typename\
    \ Argument, typename... Arguments> bool read(std::istream& in, Argument& first,\
    \ Arguments& ... rest)\n{\n\tbool result = true;\n\tresult &= read(in, first);\n\
    \tresult &= read(in, rest...);\n\treturn result;\n}\n\ntemplate<typename T, std::size_t\
    \ Size> bool read(std::istream& in, std::array<T, Size>& elements)\n{\n\tbool\
    \ result = true;\n\tfor(T& element : elements)\n\t{ result &= read(in, element);\
    \ }\n\treturn result;\n}\n\ntemplate<typename T1, typename T2> bool read(std::istream&\
    \ in, std::pair<T1, T2>& element)\n{\n\treturn read(in, element.first, element.second);\n\
    }\n\ntemplate<typename T> bool read(std::istream& in, T& element)\n{\n\treturn\
    \ static_cast<bool>(in >> element);\n}\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::complex<T>& element)\n{\n\tbool result = true;\n\tT first, second;\n\
    \tresult &= read(in, first, second);\n\telement = std::complex<T>(first, second);\n\
    \treturn result;\n}\n\ntemplate<typename T> bool read(std::istream& in, std::vector<T>&\
    \ elements)\n{\n\tbool result = true;\n\tfor(T& element : elements)\n\t{ result\
    \ &= read(in, element); }\n\treturn result;\n}\n\n\n"
  code: "#ifndef INPUT_HPP\n#define INPUT_HPP\n\n#include <array>\n#include <complex>\n\
    #include <istream>\n#include <string>\n#include <utility>\n#include <vector>\n\
    \ntemplate<typename Argument, typename... Arguments> bool read(std::istream& in,\
    \ Argument& first, Arguments& ... rest);\n\ntemplate<typename T, std::size_t N>\
    \ bool read(std::istream& in, std::array<T, N>& elements);\n\ntemplate<typename\
    \ T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element);\n\n\
    template<typename T> bool read(std::istream& in, T& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::complex<T>& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::vector<T>& elements);\n\ntemplate<typename\
    \ Argument, typename... Arguments> bool read(std::istream& in, Argument& first,\
    \ Arguments& ... rest)\n{\n\tbool result = true;\n\tresult &= read(in, first);\n\
    \tresult &= read(in, rest...);\n\treturn result;\n}\n\ntemplate<typename T, std::size_t\
    \ Size> bool read(std::istream& in, std::array<T, Size>& elements)\n{\n\tbool\
    \ result = true;\n\tfor(T& element : elements)\n\t{ result &= read(in, element);\
    \ }\n\treturn result;\n}\n\ntemplate<typename T1, typename T2> bool read(std::istream&\
    \ in, std::pair<T1, T2>& element)\n{\n\treturn read(in, element.first, element.second);\n\
    }\n\ntemplate<typename T> bool read(std::istream& in, T& element)\n{\n\treturn\
    \ static_cast<bool>(in >> element);\n}\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::complex<T>& element)\n{\n\tbool result = true;\n\tT first, second;\n\
    \tresult &= read(in, first, second);\n\telement = std::complex<T>(first, second);\n\
    \treturn result;\n}\n\ntemplate<typename T> bool read(std::istream& in, std::vector<T>&\
    \ elements)\n{\n\tbool result = true;\n\tfor(T& element : elements)\n\t{ result\
    \ &= read(in, element); }\n\treturn result;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/input.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/input.hpp
layout: document
redirect_from:
- /library/library/general/input.hpp
- /library/library/general/input.hpp.html
title: library/general/input.hpp
---
