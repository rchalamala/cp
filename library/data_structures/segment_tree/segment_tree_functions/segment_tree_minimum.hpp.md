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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../general/unused.hpp:\
    \ line -1: no such header\n"
  code: "#ifndef SEGMENT_TREE_MINIMUM_HPP\n#define SEGMENT_TREE_MINIMUM_HPP\n\n#include\
    \ <algorithm>\n#include <cstddef>\n#include <type_traits>\n\n#include \"../../../general/unused.hpp\"\
    \n\ntemplate<typename uT, std::enable_if_t<std::is_arithmetic_v<uT>, bool> = true>\
    \ struct MinimumNode\n{\n\tusing T = uT;\n\n\tT value{}, delta{}, set{};\n\tbool\
    \ validSet{};\n\n\tMinimumNode(const T& uValue, const T& uDelta, const T& uSet,\
    \ const bool& uValidSet) : value{uValue}, delta{uDelta}, set{uSet}, validSet{uValidSet}\n\
    \t{\n\t}\n\n\tMinimumNode(const T& uValue) : value{uValue}\n\t{\n\t}\n};\n\ntemplate<class\
    \ uNode> struct Minimum\n{\n\tusing Node = uNode;\n\tusing T = typename Node::T;\n\
    \n\tNode identity{};\n\n\tT return_value(const Node& element)\n\t{\n\t\treturn\
    \ element.value;\n\t}\n\n\tT value(const Node& lhs, const Node& rhs)\n\t{\n\t\t\
    return std::max(lhs.value, rhs.value);\n\t}\n\n\tvoid propagate_update(Node& parent,\
    \ Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t&\
    \ treeRight, const std::size_t& treeSize)\n\t{\n\t\tunused(treeSize);\n\t\tstd::size_t\
    \ intervalLength{treeRight - treeLeft + 1};\n\t\tif(parent.validSet)\n\t\t{\n\t\
    \t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\tleftChild.set = rightChild.set =\
    \ parent.set;\n\t\t\t\tleftChild.delta = rightChild.delta = 0;\n\t\t\t}\n\t\t\t\
    parent.value = intervalLength * parent.set;\n\t\t\tparent.validSet = false;\n\t\
    \t}\n\t\telse if(parent.delta)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\
    \t\t\t\tleftChild.delta += parent.delta;\n\t\t\t\trightChild.delta += parent.delta;\n\
    \t\t\t}\n\t\t\tparent.value += intervalLength * parent.delta;\n\t\t\tparent.delta\
    \ = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element, const T& delta)\n\t{\n\t\t\
    element.value += delta;\n\t}\n\n\tvoid change(Node& element, const T& set, const\
    \ bool& notDelta)\n\t{\n\t\tunused(notDelta);\n\t\telement.delta = 0;\n\t\telement.set\
    \ = set;\n\t\telement.validSet = true;\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
- /library/library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp.html
title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_minimum.hpp
---
