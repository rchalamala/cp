---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_composite.test.cpp
    title: verification/data_structures/segment_tree_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp\"\
    \n\n\n\n#include <cstddef>\n\ntemplate<typename T1, typename T2> T1 power(T1 base,\
    \ T2 exponent)\n{\n\tT1 result{1};\n\twhile(exponent)\n\t{\n\t\tif(exponent &\
    \ 1)\n\t\t{ result *= base; }\n\t\tbase *= base;\n\t\texponent >>= 1;\n\t}\n\t\
    return result;\n}\n\ntemplate<typename uT> struct CompositeNode\n{\n\tusing T\
    \ = uT;\n\n\tT a{1}, b{};\n\tbool validSet{};\n\n\tCompositeNode(const T& uA,\
    \ const T& uB) : a{uA}, b{uB} {}\n\n\tCompositeNode() {}\n};\n\ntemplate<class\
    \ uNode, bool ORDERED> struct Composite\n{\n\tusing Node = uNode;\n\tusing T =\
    \ typename Node::T;\n\n\tNode identity{};\n\n\tNode return_value(const Node& element)\
    \ { return element; }\n\n\tNode merge(const Node& lhs, const Node& rhs) { return\
    \ ORDERED ? Node{lhs.a * rhs.a, lhs.a * rhs.b + lhs.b} : Node{rhs.a * lhs.a, rhs.a\
    \ * lhs.b + rhs.b}; }\n\n\tvoid propagate_update(Node& parent, Node& leftChild,\
    \ Node& rightChild, const std::size_t& treeLeft, const std::size_t& treeRight,\
    \ const std::size_t& queryLeft, const std::size_t& queryRight, const std::size_t&\
    \ treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight - treeLeft + 1};\n\t\
    \tif(parent.validSet)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\t\
    leftChild.a = rightChild.a = parent.a;\n\t\t\t\tleftChild.b = rightChild.b = parent.b;\n\
    \t\t\t\tleftChild.validSet = rightChild.validSet = true;\n\t\t\t}\n\t\t\tT a =\
    \ parent.a;\n\t\t\tif(parent.a > 1)\n\t\t\t{\n\t\t\t\tparent.a = power(a, intervalLength);\n\
    \t\t\t\tparent.b *= (parent.a - 1);\n\t\t\t\tparent.b /= (a - 1);\n\t\t\t}\n\t\
    \t\telse if(parent.a == 1)\n\t\t\t{ parent.b *= intervalLength; }\n\t\t\tparent.validSet\
    \ = false;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t&\
    \ queryRight, const std::size_t& treeSize, const T& a, const T& b)\n\t{\n\t\t\
    element.a = a;\n\t\telement.b = b;\n\t\telement.validSet = true;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_COMPOSITE\n#define SEGMENT_TREE_COMPOSITE\n\n#include\
    \ <cstddef>\n\ntemplate<typename T1, typename T2> T1 power(T1 base, T2 exponent)\n\
    {\n\tT1 result{1};\n\twhile(exponent)\n\t{\n\t\tif(exponent & 1)\n\t\t{ result\
    \ *= base; }\n\t\tbase *= base;\n\t\texponent >>= 1;\n\t}\n\treturn result;\n\
    }\n\ntemplate<typename uT> struct CompositeNode\n{\n\tusing T = uT;\n\n\tT a{1},\
    \ b{};\n\tbool validSet{};\n\n\tCompositeNode(const T& uA, const T& uB) : a{uA},\
    \ b{uB} {}\n\n\tCompositeNode() {}\n};\n\ntemplate<class uNode, bool ORDERED>\
    \ struct Composite\n{\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\n\
    \tNode identity{};\n\n\tNode return_value(const Node& element) { return element;\
    \ }\n\n\tNode merge(const Node& lhs, const Node& rhs) { return ORDERED ? Node{lhs.a\
    \ * rhs.a, lhs.a * rhs.b + lhs.b} : Node{rhs.a * lhs.a, rhs.a * lhs.b + rhs.b};\
    \ }\n\n\tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize)\n\t{\n\
    \t\tstd::size_t intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.validSet)\n\
    \t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.a = rightChild.a\
    \ = parent.a;\n\t\t\t\tleftChild.b = rightChild.b = parent.b;\n\t\t\t\tleftChild.validSet\
    \ = rightChild.validSet = true;\n\t\t\t}\n\t\t\tT a = parent.a;\n\t\t\tif(parent.a\
    \ > 1)\n\t\t\t{\n\t\t\t\tparent.a = power(a, intervalLength);\n\t\t\t\tparent.b\
    \ *= (parent.a - 1);\n\t\t\t\tparent.b /= (a - 1);\n\t\t\t}\n\t\t\telse if(parent.a\
    \ == 1)\n\t\t\t{ parent.b *= intervalLength; }\n\t\t\tparent.validSet = false;\n\
    \t\t}\n\t}\n\n\tvoid change(Node& element, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize, const T& a, const T& b)\n\t{\n\t\telement.a = a;\n\
    \t\telement.b = b;\n\t\telement.validSet = true;\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp
  requiredBy: []
  timestamp: '2021-04-07 22:54:37-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/data_structures/segment_tree_composite.test.cpp
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_composite.hpp
---
