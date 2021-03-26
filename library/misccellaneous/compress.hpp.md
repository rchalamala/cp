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
  bundledCode: "#line 1 \"library/misccellaneous/compress.hpp\"\n\n\n\n// Verification:\n\
    //\n\n#include <cstddef>\n#include <map>\n#include <set>\n#include <vector>\n\n\
    template <typename T>\nstd::size_t compress(std::vector<T>& elements) {\n  std::set<T>\
    \ orderedElements;\n  for (const auto& element : elements) orderedElements.insert(element);\n\
    \  std::map<T, std::size_t> indices;\n  std::size_t index = 0;\n  for (const auto&\
    \ element : orderedElements) indices[element] = index++;\n  for (auto& element\
    \ : elements) element = static_cast<T>(indices[element]);\n  return index;\n}\n\
    \ntemplate <typename T>\nstd::size_t compress(std::vector<std::pair<T, T>>& elements)\
    \ {\n  std::set<T> orderedElements;\n  for (const auto& element : elements) {\n\
    \    orderedElements.insert(element.first);\n    orderedElements.insert(element.second);\n\
    \  }\n  std::map<T, std::size_t> indices;\n  std::size_t index = 0;\n  for (const\
    \ auto& element : orderedElements) indices[element] = index++;\n  for (auto& element\
    \ : elements) {\n    element.first = static_cast<T>(indices[element.first]);\n\
    \    element.second = static_cast<T>(indices[element.second]);\n  }\n  return\
    \ index;\n}\n\n\n"
  code: "#ifndef COMPRESS_HPP\n#define COMPRESS_HPP\n\n// Verification:\n//\n\n#include\
    \ <cstddef>\n#include <map>\n#include <set>\n#include <vector>\n\ntemplate <typename\
    \ T>\nstd::size_t compress(std::vector<T>& elements) {\n  std::set<T> orderedElements;\n\
    \  for (const auto& element : elements) orderedElements.insert(element);\n  std::map<T,\
    \ std::size_t> indices;\n  std::size_t index = 0;\n  for (const auto& element\
    \ : orderedElements) indices[element] = index++;\n  for (auto& element : elements)\
    \ element = static_cast<T>(indices[element]);\n  return index;\n}\n\ntemplate\
    \ <typename T>\nstd::size_t compress(std::vector<std::pair<T, T>>& elements) {\n\
    \  std::set<T> orderedElements;\n  for (const auto& element : elements) {\n  \
    \  orderedElements.insert(element.first);\n    orderedElements.insert(element.second);\n\
    \  }\n  std::map<T, std::size_t> indices;\n  std::size_t index = 0;\n  for (const\
    \ auto& element : orderedElements) indices[element] = index++;\n  for (auto& element\
    \ : elements) {\n    element.first = static_cast<T>(indices[element.first]);\n\
    \    element.second = static_cast<T>(indices[element.second]);\n  }\n  return\
    \ index;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/misccellaneous/compress.hpp
  requiredBy: []
  timestamp: '2021-03-20 14:37:47-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misccellaneous/compress.hpp
layout: document
redirect_from:
- /library/library/misccellaneous/compress.hpp
- /library/library/misccellaneous/compress.hpp.html
title: library/misccellaneous/compress.hpp
---
