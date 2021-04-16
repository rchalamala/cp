---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_add_sum.test.cpp
    title: verification/data_structures/segment_tree_add_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_affine.test.cpp
    title: verification/data_structures/segment_tree_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_composite.test.cpp
    title: verification/data_structures/segment_tree_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/graph/heavy_light_decomposition.test.cpp
    title: verification/graph/heavy_light_decomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/graph/heavy_light_decomposition_path.test.cpp
    title: verification/graph/heavy_light_decomposition_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/graph/heavy_light_decomposition_subtree.test.cpp
    title: verification/graph/heavy_light_decomposition_subtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/numerical/factors/optimized_rho_factorization.test.cpp
    title: verification/numerical/factors/optimized_rho_factorization.test.cpp
  - icon: ':x:'
    path: verification/numerical/factors/pollards_rho_factorization.test.cpp
    title: verification/numerical/factors/pollards_rho_factorization.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/general/speed.hpp\"\n\n\n\n#include <iostream>\n\
    \ninline bool speed()\n{\n\tstd::cin.exceptions(std::cin.failbit);\n\treturn std::cin.tie(nullptr)\
    \ && std::ios_base::sync_with_stdio(false);\n}\n\n\n"
  code: "#ifndef SPEED_HPP\n#define SPEED_HPP\n\n#include <iostream>\n\ninline bool\
    \ speed()\n{\n\tstd::cin.exceptions(std::cin.failbit);\n\treturn std::cin.tie(nullptr)\
    \ && std::ios_base::sync_with_stdio(false);\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/speed.hpp
  requiredBy: []
  timestamp: '2021-03-25 18:54:38-06:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verification/data_structures/segment_tree_affine.test.cpp
  - verification/data_structures/segment_tree_composite.test.cpp
  - verification/data_structures/segment_tree_add_sum.test.cpp
  - verification/graph/heavy_light_decomposition_subtree.test.cpp
  - verification/graph/heavy_light_decomposition_path.test.cpp
  - verification/graph/heavy_light_decomposition.test.cpp
  - verification/numerical/factors/pollards_rho_factorization.test.cpp
  - verification/numerical/factors/optimized_rho_factorization.test.cpp
documentation_of: library/general/speed.hpp
layout: document
redirect_from:
- /library/library/general/speed.hpp
- /library/library/general/speed.hpp.html
title: library/general/speed.hpp
---
