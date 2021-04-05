---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verification/graph/heavy_light_decomposition.test.cpp
    title: verification/graph/heavy_light_decomposition.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree.hpp\"\n\
    \n\n\n#include <cstddef>\n#include <vector>\n\ntemplate<class F, class Node> class\
    \ SegmentTree\n{\npublic:\n\tF f;\nprivate:\n\tconst std::size_t size;\n\tstd::vector<Node>\
    \ tree;\n\n\tvoid propagate(const std::size_t& i, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight)\n\t{\n\t\tif(treeLeft != treeRight)\n\t\t{\n\t\
    \t\tf.propagate_update(tree[i], tree[2 * i], tree[2 * i + 1], treeLeft, treeRight,\
    \ tree.size() / 4);\n\t\t\ttree[i] = f.value(tree[2 * i], tree[2 * i + 1]);\n\t\
    \t}\n\t\telse\n\t\t{\n\t\t\tf.propagate_update(tree[i], tree[i], tree[i], treeLeft,\
    \ treeRight, tree.size() / 4);\n\t\t}\n\t}\n\n\ttemplate<typename Iterable> void\
    \ build(const std::size_t& i, const std::size_t& left, const std::size_t& right,\
    \ const Iterable& elements)\n\t{\n\t\tif(left == right)\n\t\t{\n\t\t\tif(left\
    \ < elements.size())\n\t\t\t{\n\t\t\t\ttree[i] = Node{elements[left]};\n\t\t\t\
    }\n\t\t\treturn;\n\t\t}\n\t\tconst std::size_t midpoint = left + (right - left)\
    \ / 2;\n\t\tbuild(2 * i, left, midpoint, elements);\n\t\tbuild(2 * i + 1, midpoint\
    \ + 1, right, elements);\n\t\ttree[i] = f.value(tree[2 * i], tree[2 * i + 1]);\n\
    \t}\n\n\ttemplate<typename... Arguments> void change(const std::size_t i, const\
    \ std::size_t treeLeft, const std::size_t treeRight, const std::size_t& left,\
    \ const std::size_t& right, const Arguments& ... rest)\n\t{\n\t\tif(left > treeRight\
    \ || treeLeft > right)\n\t\t{ return; }\n\t\tpropagate(i, treeLeft, treeRight);\n\
    \t\tif(left <= treeLeft && treeRight <= right)\n\t\t{\n\t\t\tf.change(tree[i],\
    \ rest...);\n\t\t\tpropagate(i, treeLeft, treeRight);\n\t\t\treturn;\n\t\t}\n\t\
    \tconst std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;\n\t\tchange(2\
    \ * i, treeLeft, midpoint, left, right, rest...);\n\t\tchange(2 * i + 1, midpoint\
    \ + 1, treeRight, left, right, rest...);\n\t\ttree[i] = f.value(tree[2 * i], tree[2\
    \ * i + 1]);\n\t}\n\n\tNode range(const std::size_t& i, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)\n\
    \t{\n\t\tif(left > treeRight || treeLeft > right)\n\t\t{ return f.identity; }\n\
    \t\tpropagate(i, treeLeft, treeRight);\n\t\tif(left <= treeLeft && treeRight <=\
    \ right)\n\t\t{ return tree[i]; }\n\t\tconst std::size_t midpoint = treeLeft +\
    \ (treeRight - treeLeft) / 2;\n\t\treturn f.value(range(2 * i, treeLeft, midpoint,\
    \ left, right), range(2 * i + 1, midpoint + 1, treeRight, left, right));\n\t}\n\
    \npublic:\n\texplicit SegmentTree(const std::size_t& u_size) : size{u_size}\n\t\
    {\n\t\ttree.assign(4 * size, f.identity);\n\t}\n\n\ttemplate<typename Iterable>\
    \ void build(const Iterable& elements)\n\t{\n\t\tbuild(1, 0, size - 1, elements);\n\
    \t}\n\n\ttemplate<typename... Arguments> void change(const std::size_t& left,\
    \ const std::size_t& right, const Arguments& ... rest)\n\t{\n\t\tchange(1, 0,\
    \ size - 1, left, right, rest...);\n\t}\n\n\tauto range(const std::size_t& left,\
    \ const std::size_t& right)\n\t{\n\t\treturn f.return_value(range(1, 0, size -\
    \ 1, left, right));\n\t}\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_HPP\n#define SEGMENT_TREE_HPP\n\n#include <cstddef>\n\
    #include <vector>\n\ntemplate<class F, class Node> class SegmentTree\n{\npublic:\n\
    \tF f;\nprivate:\n\tconst std::size_t size;\n\tstd::vector<Node> tree;\n\n\tvoid\
    \ propagate(const std::size_t& i, const std::size_t& treeLeft, const std::size_t&\
    \ treeRight)\n\t{\n\t\tif(treeLeft != treeRight)\n\t\t{\n\t\t\tf.propagate_update(tree[i],\
    \ tree[2 * i], tree[2 * i + 1], treeLeft, treeRight, tree.size() / 4);\n\t\t\t\
    tree[i] = f.value(tree[2 * i], tree[2 * i + 1]);\n\t\t}\n\t\telse\n\t\t{\n\t\t\
    \tf.propagate_update(tree[i], tree[i], tree[i], treeLeft, treeRight, tree.size()\
    \ / 4);\n\t\t}\n\t}\n\n\ttemplate<typename Iterable> void build(const std::size_t&\
    \ i, const std::size_t& left, const std::size_t& right, const Iterable& elements)\n\
    \t{\n\t\tif(left == right)\n\t\t{\n\t\t\tif(left < elements.size())\n\t\t\t{\n\
    \t\t\t\ttree[i] = Node{elements[left]};\n\t\t\t}\n\t\t\treturn;\n\t\t}\n\t\tconst\
    \ std::size_t midpoint = left + (right - left) / 2;\n\t\tbuild(2 * i, left, midpoint,\
    \ elements);\n\t\tbuild(2 * i + 1, midpoint + 1, right, elements);\n\t\ttree[i]\
    \ = f.value(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\ttemplate<typename... Arguments>\
    \ void change(const std::size_t i, const std::size_t treeLeft, const std::size_t\
    \ treeRight, const std::size_t& left, const std::size_t& right, const Arguments&\
    \ ... rest)\n\t{\n\t\tif(left > treeRight || treeLeft > right)\n\t\t{ return;\
    \ }\n\t\tpropagate(i, treeLeft, treeRight);\n\t\tif(left <= treeLeft && treeRight\
    \ <= right)\n\t\t{\n\t\t\tf.change(tree[i], rest...);\n\t\t\tpropagate(i, treeLeft,\
    \ treeRight);\n\t\t\treturn;\n\t\t}\n\t\tconst std::size_t midpoint = treeLeft\
    \ + (treeRight - treeLeft) / 2;\n\t\tchange(2 * i, treeLeft, midpoint, left, right,\
    \ rest...);\n\t\tchange(2 * i + 1, midpoint + 1, treeRight, left, right, rest...);\n\
    \t\ttree[i] = f.value(tree[2 * i], tree[2 * i + 1]);\n\t}\n\n\tNode range(const\
    \ std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const\
    \ std::size_t& left, const std::size_t& right)\n\t{\n\t\tif(left > treeRight ||\
    \ treeLeft > right)\n\t\t{ return f.identity; }\n\t\tpropagate(i, treeLeft, treeRight);\n\
    \t\tif(left <= treeLeft && treeRight <= right)\n\t\t{ return tree[i]; }\n\t\t\
    const std::size_t midpoint = treeLeft + (treeRight - treeLeft) / 2;\n\t\treturn\
    \ f.value(range(2 * i, treeLeft, midpoint, left, right), range(2 * i + 1, midpoint\
    \ + 1, treeRight, left, right));\n\t}\n\npublic:\n\texplicit SegmentTree(const\
    \ std::size_t& u_size) : size{u_size}\n\t{\n\t\ttree.assign(4 * size, f.identity);\n\
    \t}\n\n\ttemplate<typename Iterable> void build(const Iterable& elements)\n\t\
    {\n\t\tbuild(1, 0, size - 1, elements);\n\t}\n\n\ttemplate<typename... Arguments>\
    \ void change(const std::size_t& left, const std::size_t& right, const Arguments&\
    \ ... rest)\n\t{\n\t\tchange(1, 0, size - 1, left, right, rest...);\n\t}\n\n\t\
    auto range(const std::size_t& left, const std::size_t& right)\n\t{\n\t\treturn\
    \ f.return_value(range(1, 0, size - 1, left, right));\n\t}\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-03-28 23:42:17-06:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verification/graph/heavy_light_decomposition.test.cpp
documentation_of: library/data_structures/segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree.hpp
- /library/library/data_structures/segment_tree/segment_tree.hpp.html
title: library/data_structures/segment_tree/segment_tree.hpp
---
