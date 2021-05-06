---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp\"\
    \n\n\n\n#include <cstddef>\n#include <type_traits>\n#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\n\n\n#line 6 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true>\
    \ struct AddNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{}, set{};\n\tbool validSet{};\n\
    \n\tAddNode(const T& uValue) : value{uValue} {}\n\n\tAddNode() {}\n};\n\ntemplate<class\
    \ uNode> struct Add\n{\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\
    \n\tNode identity{};\n\n\tvirtual T return_value(const Node& element) { return\
    \ element.value; }\n\n\tvirtual Node merge(const Node& lhs, const Node& rhs) {\
    \ return lhs.value + rhs.value; }\n\n\tvirtual void propagate_update(Node& parent,\
    \ Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t&\
    \ treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const\
    \ std::size_t& treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight - treeLeft\
    \ + 1};\n\t\tif(parent.validSet)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t\
    {\n\t\t\t\tleftChild.set = rightChild.set = parent.set;\n\t\t\t\tleftChild.validSet\
    \ = rightChild.validSet = true;\n\t\t\t\tleftChild.delta = rightChild.delta =\
    \ 0;\n\t\t\t}\n\t\t\tparent.value = static_cast<T>(intervalLength) * parent.set;\n\
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
    \ = set;\n\t\telement.validSet = true;\n\t}\n};\n\n\n#line 7 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp\"\
    \n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true>\
    \ struct ArithmeticProgressionNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{},\
    \ deltaAP{};\n\n\tArithmeticProgressionNode(const T& uValue, const T& uDelta,\
    \ const T& uDeltaAP) : value{uValue}, delta{uDelta}, deltaAP{uDeltaAP} {}\n\n\t\
    ArithmeticProgressionNode(const T& uValue) : value{uValue} {}\n\n\tArithmeticProgressionNode()\
    \ {}\n};\n\ntemplate<class uNode, bool ZEROINDEXED> struct ArithmeticProgression\n\
    {\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\n\tNode identity{};\n\
    \n\tT return_value(const Node& element) { return element.value; }\n\n\tNode merge(const\
    \ Node& lhs, const Node& rhs)\n\t{\n\t\treturn lhs.value + rhs.value;\n\t}\n\n\
    \tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild, const\
    \ std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft,\
    \ const std::size_t& queryRight, const std::size_t& treeSize)\n\t{\n\t\tstd::size_t\
    \ intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.delta)\n\t\t{\n\t\t\
    \tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.delta += parent.delta;\n\t\
    \t\t\trightChild.delta += parent.delta;\n\t\t\t}\n\t\t\tparent.value += intervalLength\
    \ * parent.delta;\n\t\t\tparent.delta = 0;\n\t\t}\n\t\tif(parent.deltaAP)\n\t\t\
    {\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.deltaAP += parent.deltaAP;\n\
    \t\t\t\trightChild.deltaAP += parent.deltaAP;\n\t\t\t\trightChild.delta += parent.deltaAP\
    \ * ((intervalLength + 1) >> 1);\n\t\t\t}\n\t\t\tparent.value += (((intervalLength\
    \ * (intervalLength + 1)) >> 1) - ZEROINDEXED) * parent.deltaAP;\n\t\t\tparent.deltaAP\
    \ = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t&\
    \ queryRight, const std::size_t& treeSize, const T& value) { element.delta +=\
    \ value; }\n\n\tvoid change(Node& element, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize, const T& k, const bool& isAP)\n\t{\n\t\telement.delta\
    \ += (treeLeft - queryLeft) * k;\n\t\telement.deltaAP += k;\n\t}\n\n\tvoid change(Node&\
    \ element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& value, const T& k)\n\t{\n\t\telement.delta += value + (treeLeft - queryLeft)\
    \ * k;\n\t\telement.deltaAP += k;\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_ARITHMETIC_PROGRESSION_HPP\n#define SEGMENT_TREE_ARITHMETIC_PROGRESSION_HPP\n\
    \n#include <cstddef>\n#include <type_traits>\n#include \"segment_tree_add.hpp\"\
    \n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true>\
    \ struct ArithmeticProgressionNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{},\
    \ deltaAP{};\n\n\tArithmeticProgressionNode(const T& uValue, const T& uDelta,\
    \ const T& uDeltaAP) : value{uValue}, delta{uDelta}, deltaAP{uDeltaAP} {}\n\n\t\
    ArithmeticProgressionNode(const T& uValue) : value{uValue} {}\n\n\tArithmeticProgressionNode()\
    \ {}\n};\n\ntemplate<class uNode, bool ZEROINDEXED> struct ArithmeticProgression\n\
    {\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\n\tNode identity{};\n\
    \n\tT return_value(const Node& element) { return element.value; }\n\n\tNode merge(const\
    \ Node& lhs, const Node& rhs)\n\t{\n\t\treturn lhs.value + rhs.value;\n\t}\n\n\
    \tvoid propagate_update(Node& parent, Node& leftChild, Node& rightChild, const\
    \ std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t& queryLeft,\
    \ const std::size_t& queryRight, const std::size_t& treeSize)\n\t{\n\t\tstd::size_t\
    \ intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.delta)\n\t\t{\n\t\t\
    \tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.delta += parent.delta;\n\t\
    \t\t\trightChild.delta += parent.delta;\n\t\t\t}\n\t\t\tparent.value += intervalLength\
    \ * parent.delta;\n\t\t\tparent.delta = 0;\n\t\t}\n\t\tif(parent.deltaAP)\n\t\t\
    {\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.deltaAP += parent.deltaAP;\n\
    \t\t\t\trightChild.deltaAP += parent.deltaAP;\n\t\t\t\trightChild.delta += parent.deltaAP\
    \ * ((intervalLength + 1) >> 1);\n\t\t\t}\n\t\t\tparent.value += (((intervalLength\
    \ * (intervalLength + 1)) >> 1) - ZEROINDEXED) * parent.deltaAP;\n\t\t\tparent.deltaAP\
    \ = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t&\
    \ queryRight, const std::size_t& treeSize, const T& value) { element.delta +=\
    \ value; }\n\n\tvoid change(Node& element, const std::size_t& treeLeft, const\
    \ std::size_t& treeRight, const std::size_t& queryLeft, const std::size_t& queryRight,\
    \ const std::size_t& treeSize, const T& k, const bool& isAP)\n\t{\n\t\telement.delta\
    \ += (treeLeft - queryLeft) * k;\n\t\telement.deltaAP += k;\n\t}\n\n\tvoid change(Node&\
    \ element, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& value, const T& k)\n\t{\n\t\telement.delta += value + (treeLeft - queryLeft)\
    \ * k;\n\t\telement.deltaAP += k;\n\t}\n};\n\n#endif"
  dependsOn:
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
  requiredBy: []
  timestamp: '2021-04-07 22:54:37-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_arithmetic_progression.hpp
---
