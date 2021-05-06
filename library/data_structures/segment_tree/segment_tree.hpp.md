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
  bundledCode: "#line 1 \"library/data_structures/segment_tree/segment_tree.hpp\"\n\
    \n\n\n#include <cstddef>\n#include <vector>\n\ntemplate<class uF> class SegmentTree\n\
    {\npublic:\n\tusing F = uF;\n\tusing Node = typename F::Node;\n\tF f;\nprivate:\n\
    \tconst std::size_t size;\n\tstd::vector <Node> tree;\n\n\tvoid propagate(const\
    \ std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const\
    \ std::size_t& left, const std::size_t& right)\n\t{\n\t\tif(treeLeft != treeRight)\n\
    \t\t{ f.propagate_update(tree[i], tree[i << 1], tree[(i << 1) ^ 1], treeLeft,\
    \ treeRight, left, right, size); }\n\t\telse\n\t\t{ f.propagate_update(tree[i],\
    \ tree[i], tree[i], treeLeft, treeRight, left, right, size); }\n\t}\n\n\ttemplate<typename\
    \ Iterable> void build(const std::size_t& i, const std::size_t& left, const std::size_t&\
    \ right, const Iterable& elements)\n\t{\n\t\tif(left == right)\n\t\t{\n\t\t\t\
    tree[i] = Node{elements[left]};\n\t\t\treturn;\n\t\t}\n\t\tconst std::size_t midpoint\
    \ = left + ((right - left) >> 1);\n\t\tbuild(i << 1, left, midpoint, elements);\n\
    \t\tbuild((i << 1) ^ 1, midpoint + 1, right, elements);\n\t\ttree[i] = f.merge(tree[i\
    \ << 1], tree[(i << 1) ^ 1]);\n\t}\n\n\ttemplate<typename... Arguments> void change(const\
    \ std::size_t& i, const std::size_t& treeLeft, const std::size_t& treeRight, const\
    \ std::size_t& left, const std::size_t& right, const Arguments& ... rest)\n\t\
    {\n\t\tpropagate(i, treeLeft, treeRight, left, right);\n\t\tif(left > treeRight\
    \ || treeLeft > right)\n\t\t{ return; }\n\t\tif(left <= treeLeft && treeRight\
    \ <= right)\n\t\t{\n\t\t\tf.change(tree[i], treeLeft, treeRight, left, right,\
    \ size, rest...);\n\t\t\tpropagate(i, treeLeft, treeRight, left, right);\n\t\t\
    \treturn;\n\t\t}\n\t\tconst std::size_t midpoint = treeLeft + ((treeRight - treeLeft)\
    \ >> 1);\n\t\tchange(i << 1, treeLeft, midpoint, left, right, rest...);\n\t\t\
    change((i << 1) ^ 1, midpoint + 1, treeRight, left, right, rest...);\n\t\ttree[i]\
    \ = f.merge(tree[i << 1], tree[(i << 1) ^ 1]);\n\t}\n\n\tNode range(const std::size_t&\
    \ i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ left, const std::size_t& right)\n\t{\n\t\tif(left > treeRight || treeLeft >\
    \ right)\n\t\t{ return f.identity; }\n\t\tpropagate(i, treeLeft, treeRight, left,\
    \ right);\n\t\tif(left <= treeLeft && treeRight <= right)\n\t\t{ return tree[i];\
    \ }\n\t\tconst std::size_t midpoint = treeLeft + ((treeRight - treeLeft) >> 1);\n\
    \t\treturn f.merge(range(i << 1, treeLeft, midpoint, left, right), range((i <<\
    \ 1) ^ 1, midpoint + 1, treeRight, left, right));\n\t}\n\npublic:\n\texplicit\
    \ SegmentTree(const std::size_t& uSize) : size{uSize} { tree.assign(size << 2,\
    \ Node{}); }\n\n\ttemplate<typename Iterable> void build(const Iterable& uElements)\
    \ { build(1, 0, size - 1, uElements); }\n\n\ttemplate<typename... Arguments> void\
    \ change(const std::size_t& left, const std::size_t& right, const Arguments& ...\
    \ rest) { change(1, 0, size - 1, left, right, rest...); }\n\n\tauto range(const\
    \ std::size_t& left, const std::size_t& right) { return f.return_value(range(1,\
    \ 0, size - 1, left, right)); }\n};\n\n\n"
  code: "#ifndef SEGMENT_TREE_HPP\n#define SEGMENT_TREE_HPP\n\n#include <cstddef>\n\
    #include <vector>\n\ntemplate<class uF> class SegmentTree\n{\npublic:\n\tusing\
    \ F = uF;\n\tusing Node = typename F::Node;\n\tF f;\nprivate:\n\tconst std::size_t\
    \ size;\n\tstd::vector <Node> tree;\n\n\tvoid propagate(const std::size_t& i,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ left, const std::size_t& right)\n\t{\n\t\tif(treeLeft != treeRight)\n\t\t{ f.propagate_update(tree[i],\
    \ tree[i << 1], tree[(i << 1) ^ 1], treeLeft, treeRight, left, right, size); }\n\
    \t\telse\n\t\t{ f.propagate_update(tree[i], tree[i], tree[i], treeLeft, treeRight,\
    \ left, right, size); }\n\t}\n\n\ttemplate<typename Iterable> void build(const\
    \ std::size_t& i, const std::size_t& left, const std::size_t& right, const Iterable&\
    \ elements)\n\t{\n\t\tif(left == right)\n\t\t{\n\t\t\ttree[i] = Node{elements[left]};\n\
    \t\t\treturn;\n\t\t}\n\t\tconst std::size_t midpoint = left + ((right - left)\
    \ >> 1);\n\t\tbuild(i << 1, left, midpoint, elements);\n\t\tbuild((i << 1) ^ 1,\
    \ midpoint + 1, right, elements);\n\t\ttree[i] = f.merge(tree[i << 1], tree[(i\
    \ << 1) ^ 1]);\n\t}\n\n\ttemplate<typename... Arguments> void change(const std::size_t&\
    \ i, const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ left, const std::size_t& right, const Arguments& ... rest)\n\t{\n\t\tpropagate(i,\
    \ treeLeft, treeRight, left, right);\n\t\tif(left > treeRight || treeLeft > right)\n\
    \t\t{ return; }\n\t\tif(left <= treeLeft && treeRight <= right)\n\t\t{\n\t\t\t\
    f.change(tree[i], treeLeft, treeRight, left, right, size, rest...);\n\t\t\tpropagate(i,\
    \ treeLeft, treeRight, left, right);\n\t\t\treturn;\n\t\t}\n\t\tconst std::size_t\
    \ midpoint = treeLeft + ((treeRight - treeLeft) >> 1);\n\t\tchange(i << 1, treeLeft,\
    \ midpoint, left, right, rest...);\n\t\tchange((i << 1) ^ 1, midpoint + 1, treeRight,\
    \ left, right, rest...);\n\t\ttree[i] = f.merge(tree[i << 1], tree[(i << 1) ^\
    \ 1]);\n\t}\n\n\tNode range(const std::size_t& i, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)\n\
    \t{\n\t\tif(left > treeRight || treeLeft > right)\n\t\t{ return f.identity; }\n\
    \t\tpropagate(i, treeLeft, treeRight, left, right);\n\t\tif(left <= treeLeft &&\
    \ treeRight <= right)\n\t\t{ return tree[i]; }\n\t\tconst std::size_t midpoint\
    \ = treeLeft + ((treeRight - treeLeft) >> 1);\n\t\treturn f.merge(range(i << 1,\
    \ treeLeft, midpoint, left, right), range((i << 1) ^ 1, midpoint + 1, treeRight,\
    \ left, right));\n\t}\n\npublic:\n\texplicit SegmentTree(const std::size_t& uSize)\
    \ : size{uSize} { tree.assign(size << 2, Node{}); }\n\n\ttemplate<typename Iterable>\
    \ void build(const Iterable& uElements) { build(1, 0, size - 1, uElements); }\n\
    \n\ttemplate<typename... Arguments> void change(const std::size_t& left, const\
    \ std::size_t& right, const Arguments& ... rest) { change(1, 0, size - 1, left,\
    \ right, rest...); }\n\n\tauto range(const std::size_t& left, const std::size_t&\
    \ right) { return f.return_value(range(1, 0, size - 1, left, right)); }\n};\n\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: library/data_structures/segment_tree/segment_tree.hpp
  requiredBy: []
  timestamp: '2021-05-06 17:00:48-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data_structures/segment_tree/segment_tree.hpp
layout: document
redirect_from:
- /library/library/data_structures/segment_tree/segment_tree.hpp
- /library/library/data_structures/segment_tree/segment_tree.hpp.html
title: library/data_structures/segment_tree/segment_tree.hpp
---
