---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/general/to_string.hpp
    title: library/general/to_string.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_add_sum.test.cpp
    title: verification/data_structures/segment_tree_add_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/graph/heavy_light_decomposition_path.test.cpp
    title: verification/graph/heavy_light_decomposition_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/graph/heavy_light_decomposition_subtree.test.cpp
    title: verification/graph/heavy_light_decomposition_subtree.test.cpp
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
  bundledCode: "#line 1 \"library/general/output.hpp\"\n\n\n\n#line 1 \"library/general/to_string.hpp\"\
    \n\n\n\n#include <bitset>\n#include <complex>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\nnamespace std\n{\n\tinline std::string to_string(const bool&\
    \ element);\n\n\tinline std::string to_string(const char& element);\n\n\tinline\
    \ std::string to_string(const char* element);\n\n\tinline std::string to_string(const\
    \ std::string& element);\n\n\tinline std::string to_string(const std::vector<bool>&\
    \ elements);\n\n\ttemplate<typename T> std::string to_string(const T& elements);\n\
    \n\ttemplate<std::size_t Size> std::string to_string(const std::bitset<Size>&\
    \ elements);\n\n\ttemplate<typename T> std::string to_string(const std::complex<T>&\
    \ element);\n\n\ttemplate<typename T1, typename T2> std::string to_string(std::pair<T1,\
    \ T2> element);\n}  // namespace std\n\ninline std::string std::to_string(const\
    \ bool& element)\n{\n#ifdef LOCAL\n\treturn element ? \"true\" : \"false\";\n\
    #else\n\treturn std::string{static_cast<char>('0' + element)};\n#endif\n}\n\n\
    inline std::string std::to_string(const char& element)\n{\n\treturn std::string(1,\
    \ element);\n}\n\ninline std::string std::to_string(const char* element)\n{\n\t\
    return std::string(element);\n}\n\ninline std::string std::to_string(const std::string&\
    \ element)\n{\n\treturn element;\n}\n\ninline std::string std::to_string(const\
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
    #endif\n}\n\n\n#line 5 \"library/general/output.hpp\"\n#include <ostream>\n\n\
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
    \n"
  code: "#ifndef OUTPUT_HPP\n#define OUTPUT_HPP\n\n#include \"to_string.hpp\"\n#include\
    \ <ostream>\n\ntemplate<typename Argument, typename... Arguments> void print(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest);\n\ntemplate<typename\
    \ Argument, typename... Arguments> void printn(std::ostream& out, const Argument&\
    \ first, const Arguments& ... rest);\n\ntemplate<typename Argument, typename...\
    \ Arguments> void prints(std::ostream& out, const Argument& first, const Arguments&\
    \ ... rest);\n\ntemplate<typename T> void print(std::ostream& out, const T& element);\n\
    \ninline void printn(std::ostream& out);\n\ninline void prints(std::ostream& out);\n\
    \ntemplate<typename T> void print(std::ostream& out, const T& element)\n{\n\t\
    out << std::to_string(element);\n}\n\ninline void printn(std::ostream& out)\n\
    {\n\tprint(out, '\\n');\n}\n\ninline void prints(std::ostream& out)\n{\n\tprint(out,\
    \ '\\n');\n}\n\ntemplate<typename Argument, typename... Arguments> void print(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\
    \tprint(out, rest...);\n}\n\ntemplate<typename Argument, typename... Arguments>\
    \ void printn(std::ostream& out, const Argument& first, const Arguments& ... rest)\n\
    {\n\tprint(out, first);\n\tif(sizeof...(rest))\n\t{ prints(out); }\n\tprintn(out,\
    \ rest...);\n}\n\ntemplate<typename Argument, typename... Arguments> void prints(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\
    \tif(sizeof...(rest))\n\t{ print(out, \" \"); }\n\tprints(out, rest...);\n}\n\n\
    #endif"
  dependsOn:
  - library/general/to_string.hpp
  isVerificationFile: false
  path: library/general/output.hpp
  requiredBy: []
  timestamp: '2021-03-26 00:48:11-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/data_structures/segment_tree_add_sum.test.cpp
  - verification/graph/heavy_light_decomposition_path.test.cpp
  - verification/graph/heavy_light_decomposition_subtree.test.cpp
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/output.hpp
layout: document
redirect_from:
- /library/library/general/output.hpp
- /library/library/general/output.hpp.html
title: library/general/output.hpp
---
