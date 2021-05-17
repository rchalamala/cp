---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
  - icon: ':warning:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_maximum.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_maximum.hpp
  - icon: ':warning:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <type_traits>\n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>,\
    \ bool> = true> struct AddNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{}, set{};\n\
    \tbool validSet{};\n\n\tAddNode(const T& uValue) : value{uValue} {}\n\n\tAddNode()\
    \ {}\n};\n\ntemplate<class uNode> struct Add\n{\n\tusing Node = uNode;\n\tusing\
    \ T = typename Node::T;\n\n\tNode identity{};\n\n\tvirtual T return_value(const\
    \ Node& element) { return element.value; }\n\n\tvirtual Node merge(const Node&\
    \ lhs, const Node& rhs) { return lhs.value + rhs.value; }\n\n\tvirtual void propagate_update(Node&\
    \ parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight\
    \ - treeLeft + 1};\n\t\tif(parent.validSet)\n\t\t{\n\t\t\tif(intervalLength >\
    \ 1)\n\t\t\t{\n\t\t\t\tleftChild.set = rightChild.set = parent.set;\n\t\t\t\t\
    leftChild.validSet = rightChild.validSet = true;\n\t\t\t\tleftChild.delta = rightChild.delta\
    \ = 0;\n\t\t\t}\n\t\t\tparent.value = static_cast<T>(intervalLength) * parent.set;\n\
    \t\t\tparent.validSet = false;\n\t\t}\n\t\tif(parent.delta)\n\t\t{\n\t\t\tif(intervalLength\
    \ > 1)\n\t\t\t{\n\t\t\t\tleftChild.delta += parent.delta;\n\t\t\t\trightChild.delta\
    \ += parent.delta;\n\t\t\t}\n\t\t\tparent.value += static_cast<T>(intervalLength)\
    \ * parent.delta;\n\t\t\tparent.delta = 0;\n\t\t}\n\t}\n\n\tvirtual void change(Node&\
    \ element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& delta) { element.delta += delta; }\n\n\tvirtual void change(Node& element,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& set, const bool& notDelta)\n\t{\n\t\telement.delta = 0;\n\t\telement.set\
    \ = set;\n\t\telement.validSet = true;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_ADD_HPP\n#define SEGMENT_TREE_ADD_HPP\n\n#include <cstddef>\n\
    #include <type_traits>\n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>,\
    \ bool> = true> struct AddNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{}, set{};\n\
    \tbool validSet{};\n\n\tAddNode(const T& uValue) : value{uValue} {}\n\n\tAddNode()\
    \ {}\n};\n\ntemplate<class uNode> struct Add\n{\n\tusing Node = uNode;\n\tusing\
    \ T = typename Node::T;\n\n\tNode identity{};\n\n\tvirtual T return_value(const\
    \ Node& element) { return element.value; }\n\n\tvirtual Node merge(const Node&\
    \ lhs, const Node& rhs) { return lhs.value + rhs.value; }\n\n\tvirtual void propagate_update(Node&\
    \ parent, Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight\
    \ - treeLeft + 1};\n\t\tif(parent.validSet)\n\t\t{\n\t\t\tif(intervalLength >\
    \ 1)\n\t\t\t{\n\t\t\t\tleftChild.set = rightChild.set = parent.set;\n\t\t\t\t\
    leftChild.validSet = rightChild.validSet = true;\n\t\t\t\tleftChild.delta = rightChild.delta\
    \ = 0;\n\t\t\t}\n\t\t\tparent.value = static_cast<T>(intervalLength) * parent.set;\n\
    \t\t\tparent.validSet = false;\n\t\t}\n\t\tif(parent.delta)\n\t\t{\n\t\t\tif(intervalLength\
    \ > 1)\n\t\t\t{\n\t\t\t\tleftChild.delta += parent.delta;\n\t\t\t\trightChild.delta\
    \ += parent.delta;\n\t\t\t}\n\t\t\tparent.value += static_cast<T>(intervalLength)\
    \ * parent.delta;\n\t\t\tparent.delta = 0;\n\t\t}\n\t}\n\n\tvirtual void change(Node&\
    \ element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& delta) { element.delta += delta; }\n\n\tvirtual void change(Node& element,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& set, const bool& notDelta)\n\t{\n\t\telement.delta = 0;\n\t\telement.set\
    \ = set;\n\t\telement.validSet = true;\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  requiredBy:
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_maximum.hpp
  timestamp: '2021-04-07 22:54:37-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/data_structures/segment_tree_add_sum.test.cpp
  - verification/graph/heavy_light_decomposition_path.test.cpp
  - verification/graph/heavy_light_decomposition_subtree.test.cpp
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
---
