---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/general/to_string.hpp
    title: library/general/to_string.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/general/output.hpp\"\n\n\n\n#line 1 \"library/general/to_string.hpp\"\
    \n\n\n\n#include <bitset>\n#include <complex>\n#include <string>\n#include <utility>\n\
    #include <vector>\n\nnamespace std\n{\n\tinline std::string to_string(const bool&\
    \ element);\n\n\tinline std::string to_string(const char& element);\n\n\tinline\
    \ std::string to_string(const char* element);\n\n\tinline std::string to_string(const\
    \ std::string& element);\n\n\ttemplate<typename T> std::string to_string(const\
    \ T& elements);\n\n\ttemplate<std::size_t Size> std::string to_string(const std::bitset<Size>&\
    \ elements);\n\n\ttemplate<typename T> std::string to_string(const std::complex<T>&\
    \ element);\n\n\ttemplate<typename T1, typename T2> std::string to_string(std::pair<T1,\
    \ T2> element);\n}  // namespace std\n\ninline std::string std::to_string(const\
    \ bool& element) { return std::string{static_cast<char>('0' + element)}; }\n\n\
    inline std::string std::to_string(const char& element) { return std::string(1,\
    \ element); }\n\ninline std::string std::to_string(const char* element) { return\
    \ std::string(element); }\n\ninline std::string std::to_string(const std::string&\
    \ element) { return element; }\n\ntemplate<typename T> std::string std::to_string(const\
    \ T& elements)\n{\n\tstd::string convert;\n\tbool first = true;\n\tfor(const auto&\
    \ element : elements)\n\t{\n\t\tif(!first)\n\t\t{ convert += \" \"; }\n\t\tfirst\
    \ = false;\n\t\tconvert += std::to_string(element);\n\t}\n\treturn convert;\n\
    }\n\ntemplate<std::size_t Size> std::string std::to_string(const std::bitset<Size>&\
    \ elements) { return elements.to_string(); }\n\ntemplate<typename T> std::string\
    \ std::to_string(const std::complex<T>& element)\n{\n\tstd::stringstream convert;\n\
    \tconvert << element;\n\treturn convert.str();\n}\n\ntemplate<typename T1, typename\
    \ T2> std::string std::to_string(std::pair<T1, T2> element) { return std::to_string(element.ff)\
    \ + \" \" + std::to_string(element.ss); }\n\n\n#line 5 \"library/general/output.hpp\"\
    \n#include <ostream>\n\ntemplate<typename Argument, typename... Arguments> void\
    \ print(const Argument& first, const Arguments& ... rest);\n\ntemplate<typename\
    \ Argument, typename... Arguments> void printn(const Argument& first, const Arguments&\
    \ ... rest);\n\ntemplate<typename Argument, typename... Arguments> void prints(const\
    \ Argument& first, const Arguments& ... rest);\n\ntemplate<typename T> void print(const\
    \ T& element);\n\ninline void printn();\n\ninline void prints();\n\ntemplate<typename\
    \ T> void print(const T& element) { std::cout << std::to_string(element); }\n\n\
    inline void printn() { print('\\n'); }\n\ninline void prints() { print('\\n');\
    \ }\n\ntemplate<typename Argument, typename... Arguments> void print(const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(first);\n\tprint(rest...);\n}\n\
    \ntemplate<typename Argument, typename... Arguments> void printn(const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(first);\n\tif(sizeof...(rest))\n\
    \t{ prints(); }\n\tprintn(rest...);\n}\n\ntemplate<typename Argument, typename...\
    \ Arguments> void prints(const Argument& first, const Arguments& ... rest)\n{\n\
    \tprint(first);\n\tif(sizeof...(rest))\n\t{ print(\" \"); }\n\tprints(rest...);\n\
    }\n\n\n"
  code: "#ifndef OUTPUT_HPP\n#define OUTPUT_HPP\n\n#include \"to_string.hpp\"\n#include\
    \ <ostream>\n\ntemplate<typename Argument, typename... Arguments> void print(const\
    \ Argument& first, const Arguments& ... rest);\n\ntemplate<typename Argument,\
    \ typename... Arguments> void printn(const Argument& first, const Arguments& ...\
    \ rest);\n\ntemplate<typename Argument, typename... Arguments> void prints(const\
    \ Argument& first, const Arguments& ... rest);\n\ntemplate<typename T> void print(const\
    \ T& element);\n\ninline void printn();\n\ninline void prints();\n\ntemplate<typename\
    \ T> void print(const T& element) { std::cout << std::to_string(element); }\n\n\
    inline void printn() { print('\\n'); }\n\ninline void prints() { print('\\n');\
    \ }\n\ntemplate<typename Argument, typename... Arguments> void print(const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(first);\n\tprint(rest...);\n}\n\
    \ntemplate<typename Argument, typename... Arguments> void printn(const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(first);\n\tif(sizeof...(rest))\n\
    \t{ prints(); }\n\tprintn(rest...);\n}\n\ntemplate<typename Argument, typename...\
    \ Arguments> void prints(const Argument& first, const Arguments& ... rest)\n{\n\
    \tprint(first);\n\tif(sizeof...(rest))\n\t{ print(\" \"); }\n\tprints(rest...);\n\
    }\n\n#endif"
  dependsOn:
  - library/general/to_string.hpp
  isVerificationFile: false
  path: library/general/output.hpp
  requiredBy: []
  timestamp: '2021-04-12 14:19:14-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/output.hpp
layout: document
redirect_from:
- /library/library/general/output.hpp
- /library/library/general/output.hpp.html
title: library/general/output.hpp
---
