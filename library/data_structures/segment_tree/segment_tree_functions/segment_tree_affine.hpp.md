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
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp\"\
    \n\n\n\n#include <cstddef>\n\n\ntemplate<typename uT> struct AffineNode\n{\n\t\
    using T = uT;\n\n\tT value{}, b{1}, c{};\n\n\tAffineNode(const T& uValue, const\
    \ T& uB, const T& uC) : value{uValue}, b{uB}, c{uC} {}\n\n\tAffineNode(const T&\
    \ uValue) : value{uValue} {}\n\n\tAffineNode() {}\n};\n\n\ntemplate<class uNode>\
    \ struct Affine\n{\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\n\t\
    Node identity{};\n\n\tT return_value(const Node& element) { return element.value;\
    \ }\n\n\tNode merge(const Node& lhs, const Node& rhs) { return lhs.value + rhs.value;\
    \ }\n\n\tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)\n\t{\n\
    \t\tstd::size_t intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.b)\n\t\
    \t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.b *= parent.b;\n\
    \t\t\t\t(leftChild.c *= parent.b) += parent.c;\n\t\t\t\trightChild.b *= parent.b;\n\
    \t\t\t\t(rightChild.c *= parent.b) += parent.c;\n\t\t\t}\n\t\t\t((parent.value\
    \ *= parent.b) += (parent.c * intervalLength));\n\t\t\tparent.b = 1;\n\t\t\tparent.c\
    \ = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t&\
    \ queryRight, const std::size_t& treeSize, const T& b, const T& c)\n\t{\n\t\t\
    element.b *= b;\n\t\t(element.c *= b) += c;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_AFFINE_HPP\n#define SEGMENT_TREE_AFFINE_HPP\n\n#include\
    \ <cstddef>\n\n\ntemplate<typename uT> struct AffineNode\n{\n\tusing T = uT;\n\
    \n\tT value{}, b{1}, c{};\n\n\tAffineNode(const T& uValue, const T& uB, const\
    \ T& uC) : value{uValue}, b{uB}, c{uC} {}\n\n\tAffineNode(const T& uValue) : value{uValue}\
    \ {}\n\n\tAffineNode() {}\n};\n\n\ntemplate<class uNode> struct Affine\n{\n\t\
    using Node = uNode;\n\tusing T = typename Node::T;\n\n\tNode identity{};\n\n\t\
    T return_value(const Node& element) { return element.value; }\n\n\tNode merge(const\
    \ Node& lhs, const Node& rhs) { return lhs.value + rhs.value; }\n\n\tvoid propagate_update(Node&\
    \ parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight\
    \ - treeLeft + 1};\n\t\tif(parent.b)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\
    \t{\n\t\t\t\tleftChild.b *= parent.b;\n\t\t\t\t(leftChild.c *= parent.b) += parent.c;\n\
    \t\t\t\trightChild.b *= parent.b;\n\t\t\t\t(rightChild.c *= parent.b) += parent.c;\n\
    \t\t\t}\n\t\t\t((parent.value *= parent.b) += (parent.c * intervalLength));\n\t\
    \t\tparent.b = 1;\n\t\t\tparent.c = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& b, const T& c)\n\t{\n\t\telement.b *= b;\n\t\t(element.c *= b) += c;\n\t\
    }\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
  requiredBy: []
  timestamp: '2021-04-07 23:26:06-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
---
