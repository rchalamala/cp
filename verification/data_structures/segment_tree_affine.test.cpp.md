---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/data_structures/segment_tree/segment_tree.hpp
    title: library/data_structures/segment_tree/segment_tree.hpp
  - icon: ':heavy_check_mark:'
    path: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
    title: library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
  - icon: ':question:'
    path: library/general/speed.hpp
    title: library/general/speed.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/modulo.hpp
    title: library/numerical/modulo.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"library/general/speed.hpp\"\n\n\n\n#include <iostream>\n\
    \ninline bool speed()\n{\n\tstd::cin.exceptions(std::cin.failbit);\n\treturn std::cin.tie(nullptr)\
    \ && std::ios_base::sync_with_stdio(false);\n}\n\n\n#line 2 \"verification/data_structures/segment_tree_affine.test.cpp\"\
    \n\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#line 8 \"verification/data_structures/segment_tree_affine.test.cpp\"\
    \n#include <vector>\n\n#line 1 \"library/data_structures/segment_tree/segment_tree.hpp\"\
    \n\n\n\n#line 6 \"library/data_structures/segment_tree/segment_tree.hpp\"\n\n\
    template<class uF> class SegmentTree\n{\npublic:\n\tusing F = uF;\n\tusing Node\
    \ = typename F::Node;\n\tF f;\nprivate:\n\tconst std::size_t size;\n\tstd::vector<Node>\
    \ tree;\n\n\tvoid propagate(const std::size_t& i, const std::size_t& treeLeft,\
    \ const std::size_t& treeRight, const std::size_t& left, const std::size_t& right)\n\
    \t{\n\t\tif(treeLeft != treeRight)\n\t\t{ f.propagate_update(tree[i], tree[i <<\
    \ 1], tree[(i << 1) ^ 1], treeLeft, treeRight, left, right, size); }\n\t\telse\n\
    \t\t{ f.propagate_update(tree[i], tree[i], tree[i], treeLeft, treeRight, left,\
    \ right, size); }\n\t}\n\n\ttemplate<typename Iterable> void build(const std::size_t&\
    \ i, const std::size_t& left, const std::size_t& right, const Iterable& elements)\n\
    \t{\n\t\tif(left == right)\n\t\t{\n\t\t\ttree[i] = Node{elements[left]};\n\t\t\
    \treturn;\n\t\t}\n\t\tconst std::size_t midpoint = left + ((right - left) >> 1);\n\
    \t\tbuild(i << 1, left, midpoint, elements);\n\t\tbuild((i << 1) ^ 1, midpoint\
    \ + 1, right, elements);\n\t\ttree[i] = f.merge(tree[i << 1], tree[(i << 1) ^\
    \ 1]);\n\t}\n\n\ttemplate<typename... Arguments> void change(const std::size_t&\
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
    \n#line 1 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp\"\
    \n\n\n\n#line 5 \"library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp\"\
    \n\n\ntemplate<typename uT> struct AffineNode\n{\n\tusing T = uT;\n\n\tT value{},\
    \ b{1}, c{};\n\n\tAffineNode(const T& uValue, const T& uB, const T& uC) : value{uValue},\
    \ b{uB}, c{uC} {}\n\n\tAffineNode(const T& uValue) : value{uValue} {}\n\n\tAffineNode()\
    \ {}\n};\n\n\ntemplate<class uNode> struct Affine\n{\n\tusing Node = uNode;\n\t\
    using T = typename Node::T;\n\n\tNode identity{};\n\n\tT return_value(const Node&\
    \ element) { return element.value; }\n\n\tNode merge(const Node& lhs, const Node&\
    \ rhs) { return lhs.value + rhs.value; }\n\n\tvoid propagate_update(Node& parent,\
    \ Node& leftChild, Node& rightChild, const std::size_t& treeLeft, const std::size_t&\
    \ treeRight, const std::size_t& queryLeft, const std::size_t& queryRight, const\
    \ std::size_t& treeSize)\n\t{\n\t\tstd::size_t intervalLength{treeRight - treeLeft\
    \ + 1};\n\t\tif(parent.b)\n\t\t{\n\t\t\tif(intervalLength > 1)\n\t\t\t{\n\t\t\t\
    \tleftChild.b *= parent.b;\n\t\t\t\t(leftChild.c *= parent.b) += parent.c;\n\t\
    \t\t\trightChild.b *= parent.b;\n\t\t\t\t(rightChild.c *= parent.b) += parent.c;\n\
    \t\t\t}\n\t\t\t((parent.value *= parent.b) += (parent.c * intervalLength));\n\t\
    \t\tparent.b = 1;\n\t\t\tparent.c = 0;\n\t\t}\n\t}\n\n\tvoid change(Node& element,\
    \ const std::size_t& treeLeft, const std::size_t& treeRight, const std::size_t&\
    \ queryLeft, const std::size_t& queryRight, const std::size_t& treeSize, const\
    \ T& b, const T& c)\n\t{\n\t\telement.b *= b;\n\t\t(element.c *= b) += c;\n\t\
    }\n};\n\n\n#line 1 \"library/numerical/modulo.hpp\"\n\n\n\n#include <algorithm>\n\
    #line 6 \"library/numerical/modulo.hpp\"\n#include <type_traits>\n\ntemplate<typename\
    \ T> T inverse(T a, T m)\n{\n\tif(a == 1)\n\t{ return 1; }\n\tT u = 0, v = 1;\n\
    \twhile(a != 0)\n\t{\n\t\tT t = m / a;\n\t\tm -= t * a;\n\t\tstd::swap(a, m);\n\
    \t\tu -= t * v;\n\t\tstd::swap(u, v);\n\t}\n\treturn u;\n}\n\n// https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp\n\
    template<typename MODULUS, std::enable_if_t<std::is_integral_v<std::decay_t<decltype(MODULUS::value)>>\
    \ && std::is_signed_v<std::decay_t<decltype(MODULUS::value)>>, bool> = true> class\
    \ Modulo\n{\n\tusing Type = typename std::decay_t<decltype(MODULUS::value)>;\n\
    \n\tType value{};\n\n\ttemplate<typename T> static T normalize(const T& element)\n\
    \t{\n\t\tType result{};\n\t\tif(-modulus() < element && element < modulus())\n\
    \t\t{\n\t\t\tresult = element;\n\t\t}\n\t\tif(result < 0)\n\t\t{ result += modulus();\
    \ }\n\t\treturn result;\n\t}\n\npublic:\n\tconstexpr static Type modulus() { return\
    \ MODULUS::value; }\n\n\tModulo() {}\n\n\ttemplate<typename T> Modulo(const T&\
    \ uValue) : value{normalize(static_cast<Type>(uValue))} {}\n\n\tconst Type& operator()()\
    \ const { return value; }\n\n\ttemplate<typename T> explicit operator T() { return\
    \ static_cast<T>(value); }\n\n\tModulo operator-() const { return Modulo{modulus()\
    \ - value}; }\n\n\tModulo operator~() const { return Modulo{inverse(value, modulus())};\
    \ }\n\n\tModulo& operator++()\n\t{\n\t\tif(++value == modulus())\n\t\t{ value\
    \ = 0; }\n\t\treturn *this;\n\t}\n\n\tModulo& operator++(int)\n\t{\n\t\tModulo\
    \ result{*this};\n\t\t++*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator--()\n\
    \t{\n\t\tif(value == 0)\n\t\t{ value = modulus(); }\n\t\t--value;\n\t\treturn\
    \ *this;\n\t}\n\n\tModulo& operator--(int)\n\t{\n\t\tModulo result{*this};\n\t\
    \t--*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator+=(const Modulo& other)\n\
    \t{\n\t\tif((value -= (modulus() - other.value)) < 0)\n\t\t{ value += modulus();\
    \ }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator+=(const\
    \ T& other) { return *this += Modulo{other}; }\n\n\tModulo& operator-=(const Modulo&\
    \ other)\n\t{\n\t\tif((value -= other.value) < 0)\n\t\t{ value += modulus(); }\n\
    \t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator-=(const T& other)\
    \ { return *this -= Modulo{other}; }\n\n\tModulo& operator*=(const Modulo& other)\n\
    \t{\n\t\tvalue = static_cast<Type>(static_cast<std::int64_t>(value) * other.value\
    \ % modulus());\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator*=(const\
    \ T& other) { return *this *= Modulo{other}; }\n\n\tModulo& operator/=(const Modulo&\
    \ other) { return *this *= ~other; }\n\n\ttemplate<typename T> Modulo& operator/=(const\
    \ T& other) { return *this /= Modulo{other}; }\n\n\ttemplate<typename T> friend\
    \ bool operator==(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\ttemplate<typename\
    \ T> friend bool operator<(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\t\
    template<typename T> friend bool operator>(const Modulo<T>& lhs, const Modulo<T>&\
    \ rhs);\n\n\ttemplate<typename T> friend std::istream& operator>>(std::istream&\
    \ in, Modulo<T>& element);\n};\n\ntemplate<typename T> bool operator==(const Modulo<T>&\
    \ lhs, const Modulo<T>& rhs) { return lhs.value == rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator==(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs == Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator==(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} == rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator!=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ == rhs); }\n\ntemplate<typename T> bool operator<(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return lhs.value < rhs.value; }\ntemplate<typename T1, typename\
    \ T2> bool operator<(const Modulo<T1>& lhs, const T2& rhs) { return lhs < Modulo<T1>{rhs};\
    \ }\ntemplate<typename T1, typename T2> bool operator<(const T1& lhs, const Modulo<T2>&\
    \ rhs) { return Modulo<T2>{lhs} < rhs; }\n\ntemplate<typename T> bool operator>(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value > rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator>(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs > Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator>(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} > rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator<=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ > rhs); }\n\ntemplate<typename T1, typename T2> bool operator>=(const T1& lhs,\
    \ const T2& rhs) { return !(lhs < rhs); }\n\ntemplate<typename T> Modulo<T> operator+(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} += rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator+(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} += rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator+(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} +=\
    \ rhs; }\n\ntemplate<typename T> Modulo<T> operator-(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return Modulo<T>{lhs} -= rhs; }\ntemplate<typename T1, typename\
    \ T2> Modulo<T1> operator-(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs}\
    \ -= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2> operator-(const T1&\
    \ lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} -= rhs; }\n\ntemplate<typename\
    \ T> Modulo<T> operator*(const Modulo<T>& lhs, const Modulo<T>& rhs) { return\
    \ Modulo<T>{lhs} *= rhs; }\ntemplate<typename T1, typename T2> Modulo<T1> operator*(const\
    \ Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} *= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T2> operator*(const T1& lhs, const Modulo<T2>& rhs)\
    \ { return Modulo<T2>{lhs} *= rhs; }\n\ntemplate<typename T> Modulo<T> operator/(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} /= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator/(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} /= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator/(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} /=\
    \ rhs; }\n\ntemplate<typename T> std::istream& operator>>(std::istream& in, Modulo<T>&\
    \ element)\n{\n\tstd::intmax_t value;\n\tin >> value;\n\tvalue %= T::value;\n\t\
    if(value < 0)\n\t{ value += T::value; }\n\telement.value = static_cast<decltype(T::value)>(value);\n\
    \treturn in;\n}\n\ntemplate<typename T> std::ostream& operator<<(std::ostream&\
    \ out, const Modulo<T>& element) { return out << element(); }\n\nnamespace std\n\
    {\n\ttemplate<typename T> std::string to_string(const Modulo<T>& element);\n}\
    \  // namespace std\n\ntemplate<typename T> std::string std::to_string(const Modulo<T>&\
    \ element) { return std::to_string(element()); }\n\n// DIVISION AND FIX UP GCD\
    \ WHEN NOT LAZY AND STATIC ASSERTIONS\n\n\n#line 13 \"verification/data_structures/segment_tree_affine.test.cpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::size_t n;\n\tstd::int32_t q;\n\tstd::cin\
    \ >> n >> q;\n\tstd::vector<std::uint64_t> a(n);\n\tfor(auto& ai : a)\n\t{ std::cin\
    \ >> ai; }\n\tSegmentTree<Affine<AffineNode<Modulo<std::integral_constant<std::decay_t<decltype(998244353)>,\
    \ 998244353>>>>> segmentTree(n);\n\tsegmentTree.build(a);\n\twhile(q--)\n\t{\n\
    \t\tbool queryType;\n\t\tstd::cin >> queryType;\n\t\tif(queryType)\n\t\t{\n\t\t\
    \tstd::size_t l, r;\n\t\t\tstd::cin >> l >> r;\n\t\t\tstd::cout << segmentTree.range(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t\telse\n\t\t{\n\t\t\tstd::size_t l, r;\n\t\t\tstd::uint64_t\
    \ b, c;\n\t\t\tstd::cin >> l >> r >> b >> c;\n\t\t\tsegmentTree.change(l, r -\
    \ 1, b, c);\n\t\t}\n\t}\n}\n"
  code: "#include \"../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../library/data_structures/segment_tree/segment_tree.hpp\"\n#include\
    \ \"../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp\"\
    \n#include \"../../library/numerical/modulo.hpp\"\n\nint main()\n{\n\tspeed();\n\
    \tstd::size_t n;\n\tstd::int32_t q;\n\tstd::cin >> n >> q;\n\tstd::vector<std::uint64_t>\
    \ a(n);\n\tfor(auto& ai : a)\n\t{ std::cin >> ai; }\n\tSegmentTree<Affine<AffineNode<Modulo<std::integral_constant<std::decay_t<decltype(998244353)>,\
    \ 998244353>>>>> segmentTree(n);\n\tsegmentTree.build(a);\n\twhile(q--)\n\t{\n\
    \t\tbool queryType;\n\t\tstd::cin >> queryType;\n\t\tif(queryType)\n\t\t{\n\t\t\
    \tstd::size_t l, r;\n\t\t\tstd::cin >> l >> r;\n\t\t\tstd::cout << segmentTree.range(l,\
    \ r - 1) << '\\n';\n\t\t}\n\t\telse\n\t\t{\n\t\t\tstd::size_t l, r;\n\t\t\tstd::uint64_t\
    \ b, c;\n\t\t\tstd::cin >> l >> r >> b >> c;\n\t\t\tsegmentTree.change(l, r -\
    \ 1, b, c);\n\t\t}\n\t}\n}\n"
  dependsOn:
  - library/general/speed.hpp
  - library/data_structures/segment_tree/segment_tree.hpp
  - library/data_structures/segment_tree/segment_tree_functions/segment_tree_affine.hpp
  - library/numerical/modulo.hpp
  isVerificationFile: true
  path: verification/data_structures/segment_tree_affine.test.cpp
  requiredBy: []
  timestamp: '2021-04-07 23:26:06-06:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verification/data_structures/segment_tree_affine.test.cpp
layout: document
redirect_from:
- /verify/verification/data_structures/segment_tree_affine.test.cpp
- /verify/verification/data_structures/segment_tree_affine.test.cpp.html
title: verification/data_structures/segment_tree_affine.test.cpp
---
