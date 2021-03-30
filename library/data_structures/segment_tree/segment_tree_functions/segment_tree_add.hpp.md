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
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <type_traits>\n\n#line 1 \"library/general/unused.hpp\"\
    \n\n\n\ntemplate<class... T> void unused(T&& ...)\n{\n}\n\n\n#line 8 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\ntemplate<typename T> struct AddNode\n{\n\tstatic_assert(std::is_arithmetic_v<T>);\n\
    \n\tT m_value{}, m_delta{}, m_set{};\n\tbool m_validSet = false;\n\n\tAddNode(const\
    \ T& value, const T& delta, const T& set, const bool& validSet) : m_value{value},\
    \ m_delta{delta}, m_set{set}, m_validSet{validSet}\n\t{\n\t}\n\n\tAddNode(const\
    \ T& value) : m_value{value}, m_delta{}, m_set{}, m_validSet{}\n\t{\n\t}\n\n\t\
    AddNode() : m_value{}, m_delta{}, m_set{}, m_validSet{}\n\t{\n\t}\n};\n\ntemplate<typename\
    \ T, typename Node> struct Add\n{\n\tstatic_assert(std::is_arithmetic_v<T>);\n\
    \n\tNode identity{};\n\n\tT return_value(const Node& element)\n\t{\n\t\treturn\
    \ element.m_value;\n\t}\n\n\tT value(const Node& lhs, const Node& rhs)\n\t{\n\t\
    \treturn lhs.m_value + rhs.m_value;\n\t}\n\n\tvoid propagate_update(Node& parent,\
    \ Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t&\
    \ treeRight, const std::size_t& treeSize)\n\t{\n\t\tunused(treeSize);\n\t\tstd::size_t\
    \ intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.m_validSet)\n\t\t{\n\
    \t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.m_set = rightChild.m_set\
    \ = parent.m_set;\n\t\t\t\tleftChild.m_delta = rightChild.m_delta = 0;\n\t\t\t\
    }\n\t\t\tparent.m_value = intervalLength * parent.m_set;\n\t\t\tparent.m_validSet\
    \ = false;\n\t\t}\n\t\telse if(parent.m_delta)\n\t\t{\n\t\t\tif(intervalLength\
    \ > 1)\n\t\t\t{\n\t\t\t\tleftChild.m_delta += parent.m_delta;\n\t\t\t\trightChild.m_delta\
    \ += parent.m_delta;\n\t\t\t}\n\t\t\tparent.m_value += intervalLength * parent.m_delta;\n\
    \t\t\tparent.m_delta = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const T&\
    \ delta)\n\t{\n\t\telement.m_value += delta;\n\t}\n\n\tvoid change(Node& element,\
    \ const T& set, const bool& notDelta)\n\t{\n\t\tunused(notDelta);\n\t\telement.m_delta\
    \ = 0;\n\t\telement.m_set = set;\n\t\telement.m_validSet = true;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_ADD_HPP\n#define SEGMENT_TREE_ADD_HPP\n\n#include <cstddef>\n\
    #include <type_traits>\n\n#include \"../../../general/unused.hpp\"\n\ntemplate<typename\
    \ T> struct AddNode\n{\n\tstatic_assert(std::is_arithmetic_v<T>);\n\n\tT m_value{},\
    \ m_delta{}, m_set{};\n\tbool m_validSet = false;\n\n\tAddNode(const T& value,\
    \ const T& delta, const T& set, const bool& validSet) : m_value{value}, m_delta{delta},\
    \ m_set{set}, m_validSet{validSet}\n\t{\n\t}\n\n\tAddNode(const T& value) : m_value{value},\
    \ m_delta{}, m_set{}, m_validSet{}\n\t{\n\t}\n\n\tAddNode() : m_value{}, m_delta{},\
    \ m_set{}, m_validSet{}\n\t{\n\t}\n};\n\ntemplate<typename T, typename Node> struct\
    \ Add\n{\n\tstatic_assert(std::is_arithmetic_v<T>);\n\n\tNode identity{};\n\n\t\
    T return_value(const Node& element)\n\t{\n\t\treturn element.m_value;\n\t}\n\n\
    \tT value(const Node& lhs, const Node& rhs)\n\t{\n\t\treturn lhs.m_value + rhs.m_value;\n\
    \t}\n\n\tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ treeSize)\n\t{\n\t\tunused(treeSize);\n\t\tstd::size_t intervalLength{treeRight\
    \ - treeLeft + 1};\n\t\tif(parent.m_validSet)\n\t\t{\n\t\t\tif(intervalLength\
    \ > 1)\n\t\t\t{\n\t\t\t\tleftChild.m_set = rightChild.m_set = parent.m_set;\n\t\
    \t\t\tleftChild.m_delta = rightChild.m_delta = 0;\n\t\t\t}\n\t\t\tparent.m_value\
    \ = intervalLength * parent.m_set;\n\t\t\tparent.m_validSet = false;\n\t\t}\n\t\
    \telse if(parent.m_delta)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\
    \tleftChild.m_delta += parent.m_delta;\n\t\t\t\trightChild.m_delta += parent.m_delta;\n\
    \t\t\t}\n\t\t\tparent.m_value += intervalLength * parent.m_delta;\n\t\t\tparent.m_delta\
    \ = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const T& delta)\n\t{\n\t\t\
    element.m_value += delta;\n\t}\n\n\tvoid change(Node& element, const T& set, const\
    \ bool& notDelta)\n\t{\n\t\tunused(notDelta);\n\t\telement.m_delta = 0;\n\t\t\
    element.m_set = set;\n\t\telement.m_validSet = true;\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
---
