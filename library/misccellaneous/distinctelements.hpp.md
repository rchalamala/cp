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
  bundledCode: "#line 1 \"library/misccellaneous/distinctelements.hpp\"\n\n\n/*\n\
    #include \"base.h\"\n#include \"input.h\"\n#include \"output.h\"\n\nusing namespace\
    \ std;\n\nconstexpr long long MAXN __attribute__((unused)) =\n\tstatic_cast<long\
    \ long>(2 * 1e5 + 1);\nconstexpr long long INF __attribute__((unused)) =\n\tstatic_cast<long\
    \ long>(1e18 + 1);\nconstexpr long long MOD __attribute__((unused)) =\n\tstatic_cast<long\
    \ long>(1e9 + 7);\nconstexpr long double EPS __attribute__((unused)) =\n\tstatic_cast<long\
    \ double>(1e-7);\n\n#include \"../datastructures/bit.hpp\"\n#include \"../graph/base/edges/bi_edge.hpp\"\
    \n#include \"../graph/base/graph.hpp\"\n#include \"../numerical/compress.hpp\"\
    \n\nclass DistinctColors {\n  void dfs(Graph<BiEdge>& graph, vector<pair<size_t,\
    \ size_t>>& times,\n\t\t   ll& current, const size_t& i = 0, const size_t& parent\
    \ = 0) {\n\ttimes[i].ff = ++current;\n\tfor (const auto& neighbor : graph[i])\n\
    \t  if (neighbor.to != parent) dfs(graph, times, current, neighbor.to, i);\n\t\
    times[i].ss = current;\n  }\n\n public:\n  void solve(std::istream& in, std::ostream&\
    \ out) {\n\tsize_t n;\n\tread(in, n);\n\tvector<ll> c(n);\n\tread(in, c);\n\t\
    auto total = compress(c);\n\tGraph<BiEdge> graph(n);\n\tfor (size_t i = 0; i <\
    \ n - 1; ++i) {\n\t  size_t a, b;\n\t  read(in, a, b);\n\t  graph.addEdge(a -\
    \ 1, b - 1);\n\t}\n\tvector<pair<size_t, size_t>> euler(n);\n\tll current = -1;\n\
    \tdfs(graph, euler, current);\n\tvector<tuple<size_t, size_t, size_t>> queries;\n\
    \tvector<ll> orderedC(n);\n\tfor (size_t i = 0; i < n; ++i) {\n\t  queries.eb(euler[i].ss,\
    \ euler[i].ff, i);\n\t  orderedC[euler[i].ff] = c[i];\n\t}\n\tFSRT(queries);\n\
    \tc = orderedC;\n\tBIT<ll> bit(n);\n\tvector<ll> last(total, -1), answer(queries.size());\n\
    \tsize_t index = 0;\n\tfor (size_t i = 0; i < n; ++i) {\n\t  if (last[c[i]] !=\
    \ -1) bit.update(last[c[i]], -1);\n\t  bit.update(last[c[i]] = i, 1);\n\t  while\
    \ (index < n && get<0>(queries[index]) == i) {\n\t\tanswer[get<2>(queries[index])]\
    \ =\n\t\t\tbit.query(get<1>(queries[index]), get<0>(queries[index]));\n\t\t++index;\n\
    \t  }\n\t}\n\tprints(out, answer);\n  }\n};\n*/\n\n"
  code: "#ifndef DISTINCTELEMENTS_HPP\n#define DISTINCTELEMENTS_HPP\n/*\n#include\
    \ \"base.h\"\n#include \"input.h\"\n#include \"output.h\"\n\nusing namespace std;\n\
    \nconstexpr long long MAXN __attribute__((unused)) =\n\tstatic_cast<long long>(2\
    \ * 1e5 + 1);\nconstexpr long long INF __attribute__((unused)) =\n\tstatic_cast<long\
    \ long>(1e18 + 1);\nconstexpr long long MOD __attribute__((unused)) =\n\tstatic_cast<long\
    \ long>(1e9 + 7);\nconstexpr long double EPS __attribute__((unused)) =\n\tstatic_cast<long\
    \ double>(1e-7);\n\n#include \"../datastructures/bit.hpp\"\n#include \"../graph/base/edges/bi_edge.hpp\"\
    \n#include \"../graph/base/graph.hpp\"\n#include \"../numerical/compress.hpp\"\
    \n\nclass DistinctColors {\n  void dfs(Graph<BiEdge>& graph, vector<pair<size_t,\
    \ size_t>>& times,\n\t\t   ll& current, const size_t& i = 0, const size_t& parent\
    \ = 0) {\n\ttimes[i].ff = ++current;\n\tfor (const auto& neighbor : graph[i])\n\
    \t  if (neighbor.to != parent) dfs(graph, times, current, neighbor.to, i);\n\t\
    times[i].ss = current;\n  }\n\n public:\n  void solve(std::istream& in, std::ostream&\
    \ out) {\n\tsize_t n;\n\tread(in, n);\n\tvector<ll> c(n);\n\tread(in, c);\n\t\
    auto total = compress(c);\n\tGraph<BiEdge> graph(n);\n\tfor (size_t i = 0; i <\
    \ n - 1; ++i) {\n\t  size_t a, b;\n\t  read(in, a, b);\n\t  graph.addEdge(a -\
    \ 1, b - 1);\n\t}\n\tvector<pair<size_t, size_t>> euler(n);\n\tll current = -1;\n\
    \tdfs(graph, euler, current);\n\tvector<tuple<size_t, size_t, size_t>> queries;\n\
    \tvector<ll> orderedC(n);\n\tfor (size_t i = 0; i < n; ++i) {\n\t  queries.eb(euler[i].ss,\
    \ euler[i].ff, i);\n\t  orderedC[euler[i].ff] = c[i];\n\t}\n\tFSRT(queries);\n\
    \tc = orderedC;\n\tBIT<ll> bit(n);\n\tvector<ll> last(total, -1), answer(queries.size());\n\
    \tsize_t index = 0;\n\tfor (size_t i = 0; i < n; ++i) {\n\t  if (last[c[i]] !=\
    \ -1) bit.update(last[c[i]], -1);\n\t  bit.update(last[c[i]] = i, 1);\n\t  while\
    \ (index < n && get<0>(queries[index]) == i) {\n\t\tanswer[get<2>(queries[index])]\
    \ =\n\t\t\tbit.query(get<1>(queries[index]), get<0>(queries[index]));\n\t\t++index;\n\
    \t  }\n\t}\n\tprints(out, answer);\n  }\n};\n*/\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/misccellaneous/distinctelements.hpp
  requiredBy: []
  timestamp: '2021-03-20 14:37:47-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/misccellaneous/distinctelements.hpp
layout: document
redirect_from:
- /library/library/misccellaneous/distinctelements.hpp
- /library/library/misccellaneous/distinctelements.hpp.html
title: library/misccellaneous/distinctelements.hpp
---
