---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verification/data_structures/segment_tree_affine.test.cpp
    title: verification/data_structures/segment_tree_affine.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp\"\
    \n\n\n\n#include <cstddef>\n\ntemplate<class uT> struct Affine\n{\n\tusing T =\
    \ typename Node::T;\n\n\tstruct Node\n\t{\n\t\tT value{}, b{1}, c{};\n\n\t\tAffineNode(const\
    \ T& uValue, const T& uB, const T& uC) : value{uValue}, b{uB}, c{uC} {}\n\n\t\t\
    AffineNode(const T& uValue) : value{uValue} {}\n\n\t\tAffineNode() {}\n\t};\n\n\
    \tNode identity{};\n\n\tT return_value(const Node& element) { return element.value;\
    \ }\n\n\tNode merge(const Node& lhs, const Node& rhs)\n\t{\n\t\treturn lhs.value\
    \ + rhs.value;\n\t}\n\n\tvoid propagate_update(Node& parent, Node& leftChild,\
    \ Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight,\
    \ const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t&\
    \ treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight - treeLeft + 1};\n\t\
    \tif(parent.b)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.b\
    \ *= parent.b;\n\t\t\t\t(leftChild.c *= parent.b) += parent.c;\n\t\t\t\trightChild.b\
    \ *= parent.b;\n\t\t\t\t(rightChild.c *= parent.b) += parent.c;\n\t\t\t}\n\t\t\
    \t((parent.value *= parent.b) += (parent.c * intervalLength));\n\t\t\tparent.b\
    \ = 1;\n\t\t\tparent.c = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const\
    \ std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft,\
    \ const std::size_t& queryRight, const std::size_t& treeSize, const T& b, const\
    \ T& c)\n\t{\n\t\telement.b *= b;\n\t\t(element.c *= b) += c;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_AFFINE_HPP\n#define SEGMENT_TREE_AFFINE_HPP\n\n#include\
    \ <cstddef>\n\ntemplate<class uT> struct Affine\n{\n\tusing T = typename Node::T;\n\
    \n\tstruct Node\n\t{\n\t\tT value{}, b{1}, c{};\n\n\t\tAffineNode(const T& uValue,\
    \ const T& uB, const T& uC) : value{uValue}, b{uB}, c{uC} {}\n\n\t\tAffineNode(const\
    \ T& uValue) : value{uValue} {}\n\n\t\tAffineNode() {}\n\t};\n\n\tNode identity{};\n\
    \n\tT return_value(const Node& element) { return element.value; }\n\n\tNode merge(const\
    \ Node& lhs, const Node& rhs)\n\t{\n\t\treturn lhs.value + rhs.value;\n\t}\n\n\
    \tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild, const\
    \ std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft,\
    \ const std::size_t& queryRight, const std::size_t& treeSize)\n\t{\n\t\tstd::size_t\
    \ intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.b)\n\t\t{\n\t\t\tif(intervalLength\
    \ > 1)\n\t\t\t{\n\t\t\t\tleftChild.b *= parent.b;\n\t\t\t\t(leftChild.c *= parent.b)\
    \ += parent.c;\n\t\t\t\trightChild.b *= parent.b;\n\t\t\t\t(rightChild.c *= parent.b)\
    \ += parent.c;\n\t\t\t}\n\t\t\t((parent.value *= parent.b) += (parent.c * intervalLength));\n\
    \t\t\tparent.b = 1;\n\t\t\tparent.c = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& b, const T& c)\n\t{\n\t\telement.b *= b;\n\t\t(element.c *= b) += c;\n\t\
    }\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
  requiredBy: []
  timestamp: '2021-04-07 22:54:37-06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verification/data_structures/segment_tree_affine.test.cpp
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
---
