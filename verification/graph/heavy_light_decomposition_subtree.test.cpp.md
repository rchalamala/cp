---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structures/segment_tree/segment_tree.hpp
    title: library/data_structures/segment_tree/segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/input.hpp
    title: library/general/input.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/output.hpp
    title: library/general/output.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/speed.hpp
    title: library/general/speed.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/to_string.hpp
    title: library/general/to_string.hpp
  - icon: ':heavy_check_mark:'
    path: library/general/unused.hpp
    title: library/general/unused.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/heavy_light_decomposition.hpp
    title: library/graph/heavy_light_decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"library/general/input.hpp\"\n\n\n\n#include <array>\n#include\
    \ <complex>\n#include <istream>\n#include <string>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate<typename Argument, typename... Arguments> bool read(std::istream&\
    \ in, Argument& first, Arguments& ... rest);\n\ntemplate<typename T, std::size_t\
    \ N> bool read(std::istream& in, std::array<T, N>& elements);\n\ntemplate<typename\
    \ T1, typename T2> bool read(std::istream& in, std::pair<T1, T2>& element);\n\n\
    template<typename T> bool read(std::istream& in, T& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::complex<T>& element);\n\ntemplate<typename\
    \ T> bool read(std::istream& in, std::vector<T>& elements);\n\ntemplate<typename\
    \ Argument, typename... Arguments> bool read(std::istream& in, Argument& first,\
    \ Arguments& ... rest)\n{\n\tbool result = true;\n\tresult &= read(in, first);\n\
    \tresult &= read(in, rest...);\n\treturn result;\n}\n\ntemplate<typename T, std::size_t\
    \ Size> bool read(std::istream& in, std::array<T, Size>& elements)\n{\n\tbool\
    \ result = true;\n\tfor(T& element : elements)\n\t{ result &= read(in, element);\
    \ }\n\treturn result;\n}\n\ntemplate<typename T1, typename T2> bool read(std::istream&\
    \ in, std::pair<T1, T2>& element)\n{\n\treturn read(in, element.first, element.second);\n\
    }\n\ntemplate<typename T> bool read(std::istream& in, T& element)\n{\n\treturn\
    \ static_cast<bool>(in >> element);\n}\n\ntemplate<typename T> bool read(std::istream&\
    \ in, std::complex<T>& element)\n{\n\tbool result = true;\n\tT first, second;\n\
    \tresult &= read(in, first, second);\n\telement = std::complex<T>(first, second);\n\
    \treturn result;\n}\n\ntemplate<typename T> bool read(std::istream& in, std::vector<T>&\
    \ elements)\n{\n\tbool result = true;\n\tfor(T& element : elements)\n\t{ result\
    \ &= read(in, element); }\n\treturn result;\n}\n\n\n#line 1 \"library/general/output.hpp\"\
    \n\n\n\n#line 1 \"library/general/to_string.hpp\"\n\n\n\n#include <bitset>\n#line\
    \ 9 \"library/general/to_string.hpp\"\n\nnamespace std\n{\n\tinline std::string\
    \ to_string(const bool& element);\n\n\tinline std::string to_string(const char&\
    \ element);\n\n\tinline std::string to_string(const char* element);\n\n\tinline\
    \ std::string to_string(const std::string& element);\n\n\ttemplate<typename T>\
    \ std::string to_string(const T& elements);\n\n\ttemplate<std::size_t Size> std::string\
    \ to_string(const std::bitset<Size>& elements);\n\n\ttemplate<typename T> std::string\
    \ to_string(const std::complex<T>& element);\n\n\ttemplate<typename T1, typename\
    \ T2> std::string to_string(std::pair<T1, T2> element);\n}  // namespace std\n\
    \ninline std::string std::to_string(const bool& element)\n{\n\treturn std::string{static_cast<char>('0'\
    \ + element)};\n}\n\ninline std::string std::to_string(const char& element)\n\
    {\n\treturn std::string(1, element);\n}\n\ninline std::string std::to_string(const\
    \ char* element)\n{\n\treturn std::string(element);\n}\n\ninline std::string std::to_string(const\
    \ std::string& element)\n{\n\treturn element;\n}\n\ntemplate<typename T> std::string\
    \ std::to_string(const T& elements)\n{\n\tstd::string convert;\n\tbool first =\
    \ true;\n\tfor(const auto& element : elements)\n\t{\n\t\tif(!first)\n\t\t{ convert\
    \ += \" \"; }\n\t\tfirst = false;\n\t\tconvert += std::to_string(element);\n\t\
    }\n\treturn convert;\n}\n\ntemplate<std::size_t Size> std::string std::to_string(const\
    \ std::bitset<Size>& elements)\n{\n\treturn elements.to_string();\n}\n\ntemplate<typename\
    \ T> std::string std::to_string(const std::complex<T>& element)\n{\n\tstd::stringstream\
    \ convert;\n\tconvert << element;\n\treturn convert.str();\n}\n\ntemplate<typename\
    \ T1, typename T2> std::string std::to_string(std::pair<T1, T2> element)\n{\n\t\
    return std::to_string(element.ff) + \" \" + std::to_string(element.ss);\n}\n\n\
    \n#line 5 \"library/general/output.hpp\"\n#include <ostream>\n\ntemplate<typename\
    \ Argument, typename... Arguments> void print(std::ostream& out, const Argument&\
    \ first, const Arguments& ... rest);\n\ntemplate<typename Argument, typename...\
    \ Arguments> void printn(std::ostream& out, const Argument& first, const Arguments&\
    \ ... rest);\n\ntemplate<typename Argument, typename... Arguments> void prints(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest);\n\ntemplate<typename\
    \ T> void print(std::ostream& out, const T& element);\n\ninline void printn(std::ostream&\
    \ out);\n\ninline void prints(std::ostream& out);\n\ntemplate<typename T> void\
    \ print(std::ostream& out, const T& element)\n{\n\tout << std::to_string(element);\n\
    }\n\ninline void printn(std::ostream& out)\n{\n\tprint(out, '\\n');\n}\n\ninline\
    \ void prints(std::ostream& out)\n{\n\tprint(out, '\\n');\n}\n\ntemplate<typename\
    \ Argument, typename... Arguments> void print(std::ostream& out, const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\tprint(out, rest...);\n\
    }\n\ntemplate<typename Argument, typename... Arguments> void printn(std::ostream&\
    \ out, const Argument& first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\
    \tif(sizeof...(rest))\n\t{ prints(out); }\n\tprintn(out, rest...);\n}\n\ntemplate<typename\
    \ Argument, typename... Arguments> void prints(std::ostream& out, const Argument&\
    \ first, const Arguments& ... rest)\n{\n\tprint(out, first);\n\tif(sizeof...(rest))\n\
    \t{ print(out, \" \"); }\n\tprints(out, rest...);\n}\n\n\n#line 1 \"library/general/speed.hpp\"\
    \n\n\n\n#include <iostream>\n\ninline bool speed()\n{\n\tstd::cin.exceptions(std::cin.failbit);\n\
    \treturn std::cin.tie(nullptr) && std::ios_base::sync_with_stdio(false);\n}\n\n\
    \n#line 4 \"verification/graph/heavy_light_decomposition_subtree.test.cpp\"\n\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n\
    #include <cstddef>\n#include <cstdint>\n#line 11 \"verification/graph/heavy_light_decomposition_subtree.test.cpp\"\
    \n\n#line 1 \"library/graph/heavy_light_decomposition.hpp\"\n\n\n\n#include <cassert>\n\
    #line 6 \"library/graph/heavy_light_decomposition.hpp\"\n#include <type_traits>\n\
    #line 9 \"library/graph/heavy_light_decomposition.hpp\"\n\ntemplate<class Tree>\
    \ class HeavyLightDecomposition\n{\n\tstd::vector<std::size_t> sizes, parent,\
    \ depths, head;\n\tstd::vector<std::pair<std::size_t, std::size_t>> times;\n\t\
    Tree tree;\n\n\tvoid dfs(std::vector<std::vector<std::size_t>>& graph, const std::size_t&\
    \ i)\n\t{\n\t\tsizes[i] = 1;\n\t\tfor(auto& child : graph[i])\n\t\t{\n\t\t\tif(child\
    \ != parent[i])\n\t\t\t{\n\t\t\t\tparent[child] = i;\n\t\t\t\tdepths[child] =\
    \ depths[i] + 1;\n\t\t\t\tdfs(graph, child);\n\t\t\t\tsizes[i] += sizes[child];\n\
    \t\t\t\tif(graph[i][0] == parent[i] || sizes[child] > sizes[graph[i][0]])\n\t\t\
    \t\t{ std::swap(graph[i][0], child); }\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::size_t currentTime\
    \ = 0;\n\n\tvoid decompose(std::vector<std::vector<std::size_t>>& graph, const\
    \ std::size_t& i)\n\t{\n\t\ttimes[i].first = currentTime++;\n\t\tfor(const auto&\
    \ child : graph[i])\n\t\t{\n\t\t\tif(child != parent[i])\n\t\t\t{\n\t\t\t\thead[child]\
    \ = (graph[i][0] == child ? head[i] : child);\n\t\t\t\tdecompose(graph, child);\n\
    \t\t\t}\n\t\t}\n\t\ttimes[i].second = currentTime - 1;\n\t}\n\n\ttemplate<typename\
    \ Operation> void path(std::size_t u, std::size_t v, const Operation operation)\n\
    \t{\n\t\tfor(; head[u] != head[v]; v = parent[head[v]])\n\t\t{\n\t\t\tif(depths[head[u]]\
    \ > depths[head[v]])\n\t\t\t{ std::swap(u, v); }\n\t\t\toperation(times[head[v]].first,\
    \ times[v].first);\n\t\t}\n\t\tif(depths[u] > depths[v])\n\t\t{ std::swap(u, v);\
    \ }\n\t\toperation(times[u].first, times[v].first);\n\t}\n\npublic:\n\texplicit\
    \ HeavyLightDecomposition(std::vector<std::vector<std::size_t>>& graph, const\
    \ std::size_t& root = 0) : sizes(graph.size()), parent(graph.size()), depths(graph.size()),\
    \ head(graph.size()), times(graph.size()), tree{graph.size()}\n\t{\n\t\tparent[root]\
    \ = root;\n\t\tdepths[root] = 0;\n\t\tdfs(graph, root);\n\t\thead[root] = root;\n\
    \t\tdecompose(graph, root);\n\t}\n\n\ttemplate<typename Iterable> void build(const\
    \ Iterable& elements)\n\t{\n\t\tassert(elements.size() && elements.size() <= std::size(sizes));\n\
    \t\tIterable positionedElements(elements.size());\n\t\tfor(std::size_t i = 0;\
    \ i < positionedElements.size(); ++i)\n\t\t{ positionedElements[times[i].first]\
    \ = elements[i]; }\n\t\ttree.build(positionedElements);\n\t}\n\n\ttemplate<typename...\
    \ Arguments> void update_sub_tree(const std::size_t& i, const Arguments& ... rest)\n\
    \t{\n\t\ttree.change(times[i].first, times[i].second, rest...);\n\t}\n\n\ttemplate<typename...\
    \ Arguments> void update_path(std::size_t u, std::size_t v, const Arguments& ...\
    \ rest)\n\t{\n\t\tpath(u, v, [this, &rest...](const std::size_t& low, const std::size_t&\
    \ high)\n\t\t{ tree.change(low, high, rest...); });\n\t}\n\n\tauto range(const\
    \ std::size_t& i)\n\t{\n\t\treturn tree.range(times[i].first, times[i].second);\n\
    \t}\n\n\tauto range(const std::size_t& u, const std::size_t& v)\n\t{\n\t\tauto\
    \ result{tree.f.identity};\n\t\tpath(u, v, [this, &result](const std::size_t&\
    \ left, const std::size_t& right)\n\t\t{ result = tree.f.value(result, tree.range(left,\
    \ right)); });\n\t\treturn tree.f.return_value(result);\n\t}\n};\n\n\n\n#line\
    \ 1 \"library/data_structures/segment_tree/segment_tree.hpp\"\n\n\n\n#line 6 \"\
    library/data_structures/segment_tree/segment_tree.hpp\"\n\ntemplate<class F, class\
    \ Node> class SegmentTree\n{\npublic:\n\tF f;\nprivate:\n\tconst std::size_t size;\n\
    \tstd::vector<Node> tree;\n\n\tvoid propagate(const std::size_t& i, const std::size_t&\
    \ treeLeft, const std::size_t& treeRight)\n\t{\n\t\tif(treeLeft != treeRight)\n\
    \t\t{\n\t\t\tf.propagate_update(tree[i], tree[2 * i], tree[2 * i + 1], treeLeft,\
    \ treeRight, tree.size() / 4);\n\t\t\ttree[i] = f.value(tree[2 * i], tree[2 *\
    \ i + 1]);\n\t\t}\n\t\telse\n\t\t{\n\t\t\tf.propagate_update(tree[i], tree[i],\
    \ tree[i], treeLeft, treeRight, tree.size() / 4);\n\t\t}\n\t}\n\n\ttemplate<typename\
    \ Iterable> void build(const std::size_t& i, const std::size_t& left, const std::size_t&\
    \ right, const Iterable& elements)\n\t{\n\t\tif(left == right)\n\t\t{\n\t\t\t\
    if(left < elements.size())\n\t\t\t{\n\t\t\t\ttree[i] = Node{elements[left]};\n\
    \t\t\t}\n\t\t\treturn;\n\t\t}\n\t\tconst std::size_t midpoint = left + (right\
    \ - left) / 2;\n\t\tbuild(2 * i, left, midpoint, elements);\n\t\tbuild(2 * i +\
    \ 1, midpoint + 1, right, elements);\n\t\ttree[i] = f.value(tree[2 * i], tree[2\
    \ * i + 1]);\n\t}\n\n\ttemplate<typename... Arguments> void change(const std::size_t\
    \ i, const std::size_t treeLeft, const std::size_t treeRight, const std::size_t&\
    \ left, const std::size_t& right, const Arguments& ... rest)\n\t{\n\t\tif(left\
    \ > treeRight || treeLeft > right)\n\t\t{ return; }\n\t\tpropagate(i, treeLeft,\
    \ treeRight);\n\t\tif(left <= treeLeft && treeRight <= right)\n\t\t{\n\t\t\tf.change(tree[i],\
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
    \ 1, left, right));\n\t}\n};\n\n\n#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\n\n\n#line 6 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\n#line 1 \"library/general/unused.hpp\"\n\n\n\ntemplate<class... T> void unused(T&&\
    \ ...)\n{\n}\n\n\n#line 8 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
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
    \ = 0;\n\t\telement.m_set = set;\n\t\telement.m_validSet = true;\n\t}\n};\n\n\n\
    #line 15 \"verification/graph/heavy_light_decomposition_subtree.test.cpp\"\n\n\
    int main()\n{\n\tspeed();\n\tstd::size_t n;\n\tstd::int_fast32_t q;\n\tread(std::cin,\
    \ n, q);\n\tstd::vector<std::uint_fast64_t> a(n);\n\tread(std::cin, a);\n\tstd::vector<std::vector<std::size_t>>\
    \ graph(n);\n\tfor(std::size_t i = 1; i < n; ++i)\n\t{\n\t\tstd::size_t p;\n\t\
    \tread(std::cin, p);\n\t\tgraph[i].push_back(p);\n\t\tgraph[p].push_back(i);\n\
    \t}\n\tHeavyLightDecomposition<SegmentTree<Add<std::uint_fast64_t, AddNode<std::uint_fast64_t>>,\
    \ AddNode<std::uint_fast64_t>>> hld(graph);\n\thld.build(a);\n\twhile(q--)\n\t\
    {\n\t\tbool queryType;\n\t\tread(std::cin, queryType);\n\t\tif(queryType)\n\t\t\
    {\n\t\t\tstd::size_t u;\n\t\t\tread(std::cin, u);\n\t\t\tprintn(std::cout, hld.range(u));\n\
    \t\t}\n\t\telse\n\t\t{\n\t\t\tstd::size_t u;\n\t\t\tstd::uint_fast64_t x;\n\t\t\
    \tread(std::cin, u, x);\n\t\t\thld.update_path(u, u, x);\n\t\t}\n\t}\n}\n"
  code: "#include \"../../library/general/input.hpp\"\n#include \"../../library/general/output.hpp\"\
    \n#include \"../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../library/graph/heavy_light_decomposition.hpp\"\n#include \"\
    ../../library/data_structures/segment_tree/segment_tree.hpp\"\n#include \"../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::size_t n;\n\tstd::int_fast32_t q;\n\tread(std::cin,\
    \ n, q);\n\tstd::vector<std::uint_fast64_t> a(n);\n\tread(std::cin, a);\n\tstd::vector<std::vector<std::size_t>>\
    \ graph(n);\n\tfor(std::size_t i = 1; i < n; ++i)\n\t{\n\t\tstd::size_t p;\n\t\
    \tread(std::cin, p);\n\t\tgraph[i].push_back(p);\n\t\tgraph[p].push_back(i);\n\
    \t}\n\tHeavyLightDecomposition<SegmentTree<Add<std::uint_fast64_t, AddNode<std::uint_fast64_t>>,\
    \ AddNode<std::uint_fast64_t>>> hld(graph);\n\thld.build(a);\n\twhile(q--)\n\t\
    {\n\t\tbool queryType;\n\t\tread(std::cin, queryType);\n\t\tif(queryType)\n\t\t\
    {\n\t\t\tstd::size_t u;\n\t\t\tread(std::cin, u);\n\t\t\tprintn(std::cout, hld.range(u));\n\
    \t\t}\n\t\telse\n\t\t{\n\t\t\tstd::size_t u;\n\t\t\tstd::uint_fast64_t x;\n\t\t\
    \tread(std::cin, u, x);\n\t\t\thld.update_path(u, u, x);\n\t\t}\n\t}\n}\n"
  dependsOn:
  - library/general/input.hpp
  - library/general/output.hpp
  - library/general/to_string.hpp
  - library/general/speed.hpp
  - library/graph/heavy_light_decomposition.hpp
  - library/data_structures/segment_tree/segment_tree.hpp
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp
  - library/general/unused.hpp
  isVerificationFile: true
  path: verification/graph/heavy_light_decomposition_subtree.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 23:42:17-06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verification/graph/heavy_light_decomposition_subtree.test.cpp
layout: document
redirect_from:
- /verify/verification/graph/heavy_light_decomposition_subtree.test.cpp
- /verify/verification/graph/heavy_light_decomposition_subtree.test.cpp.html
title: verification/graph/heavy_light_decomposition_subtree.test.cpp
---
