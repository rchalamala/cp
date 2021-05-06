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
  bundledCode: "#line 1 \"library/graph/heavy_light_decomposition.hpp\"\n\n\n\n#include\
    \ <cstddef>\n#include <type_traits>\n#include <utility>\n#include <array>\n\n\
    template<class Tree> class HeavyLightDecomposition\n{\n\tstd::vector <std::size_t>\
    \ sizes, parent, depths, head;\n\tstd::vector <std::pair<std::size_t, std::size_t>>\
    \ times;\n\tTree tree;\n\n\tvoid dfs(std::vector <std::vector<std::size_t>>& graph,\
    \ const std::size_t& i)\n\t{\n\t\tsizes[i] = 1;\n\t\tfor(auto& child : graph[i])\n\
    \t\t{\n\t\t\tif(child != parent[i])\n\t\t\t{\n\t\t\t\tparent[child] = i;\n\t\t\
    \t\tdepths[child] = depths[i] + 1;\n\t\t\t\tdfs(graph, child);\n\t\t\t\tsizes[i]\
    \ += sizes[child];\n\t\t\t\tif(graph[i][0] == parent[i] || sizes[child] > sizes[graph[i][0]])\n\
    \t\t\t\t{ std::swap(graph[i][0], child); }\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::size_t\
    \ currentTime = 0;\n\n\tvoid decompose(std::vector <std::vector<std::size_t>>&\
    \ graph, const std::size_t& i)\n\t{\n\t\ttimes[i].first = currentTime++;\n\t\t\
    for(const auto& child : graph[i])\n\t\t{\n\t\t\tif(child != parent[i])\n\t\t\t\
    {\n\t\t\t\thead[child] = (graph[i][0] == child ? head[i] : child);\n\t\t\t\tdecompose(graph,\
    \ child);\n\t\t\t}\n\t\t}\n\t\ttimes[i].second = currentTime - 1;\n\t}\n\n\ttemplate<typename\
    \ F> void path(std::size_t u, std::size_t v, const F f)\n\t{\n\t\tfor(; head[u]\
    \ != head[v]; v = parent[head[v]])\n\t\t{\n\t\t\tif(depths[head[u]] > depths[head[v]])\n\
    \t\t\t{ std::swap(u, v); }\n\t\t\tf(times[head[v]].first, times[v].first);\n\t\
    \t}\n\t\tif(depths[u] > depths[v])\n\t\t{ std::swap(u, v); }\n\t\tf(times[u].first,\
    \ times[v].first);\n\t}\n\npublic:\n\texplicit HeavyLightDecomposition(std::vector\
    \ <std::vector<std::size_t>>& graph, const std::size_t& root = 0) : sizes(graph.size()),\
    \ parent(graph.size()), depths(graph.size()), head(graph.size()), times(graph.size()),\
    \ tree{graph.size()}\n\t{\n\t\tparent[root] = root;\n\t\tdepths[root] = 0;\n\t\
    \tdfs(graph, root);\n\t\thead[root] = root;\n\t\tdecompose(graph, root);\n\t}\n\
    \n\ttemplate<typename Iterable> void build(const Iterable& elements)\n\t{\n\t\t\
    Iterable positionedElements(elements.size());\n\t\tfor(std::size_t i = 0; i <\
    \ positionedElements.size(); ++i)\n\t\t{ positionedElements[times[i].first] =\
    \ elements[i]; }\n\t\ttree.build(positionedElements);\n\t}\n\n\ttemplate<typename...\
    \ Arguments> void update_sub_tree(const std::size_t& i, const Arguments& ... rest)\
    \ { tree.change(times[i].first, times[i].second, rest...); }\n\n\ttemplate<typename...\
    \ Arguments> void update_path(std::size_t u, std::size_t v, const Arguments& ...\
    \ rest)\n\t{\n\t\tpath(u, v, [this, &rest...](const std::size_t& low, const std::size_t&\
    \ high)\n\t\t{ tree.change(low, high, rest...); });\n\t}\n\n\tauto range(const\
    \ std::size_t& i) { return tree.range(times[i].first, times[i].second); }\n\n\t\
    auto range(const std::size_t& u, const std::size_t& v)\n\t{\n\t\tauto result{tree.f.identity};\n\
    \t\tpath(u, v, [this, &result](const std::size_t& left, const std::size_t& right)\n\
    \t\t{ result = tree.f.merge(result, tree.range(left, right)); });\n\t\treturn\
    \ tree.f.return_value(result);\n\t}\n};\n\n\n\n"
  code: "#ifndef HEAVY_LIGHT_DECOMPOSITION_HPP\n#define HEAVY_LIGHT_DECOMPOSITION_HPP\n\
    \n#include <cstddef>\n#include <type_traits>\n#include <utility>\n#include <array>\n\
    \ntemplate<class Tree> class HeavyLightDecomposition\n{\n\tstd::vector <std::size_t>\
    \ sizes, parent, depths, head;\n\tstd::vector <std::pair<std::size_t, std::size_t>>\
    \ times;\n\tTree tree;\n\n\tvoid dfs(std::vector <std::vector<std::size_t>>& graph,\
    \ const std::size_t& i)\n\t{\n\t\tsizes[i] = 1;\n\t\tfor(auto& child : graph[i])\n\
    \t\t{\n\t\t\tif(child != parent[i])\n\t\t\t{\n\t\t\t\tparent[child] = i;\n\t\t\
    \t\tdepths[child] = depths[i] + 1;\n\t\t\t\tdfs(graph, child);\n\t\t\t\tsizes[i]\
    \ += sizes[child];\n\t\t\t\tif(graph[i][0] == parent[i] || sizes[child] > sizes[graph[i][0]])\n\
    \t\t\t\t{ std::swap(graph[i][0], child); }\n\t\t\t}\n\t\t}\n\t}\n\n\tstd::size_t\
    \ currentTime = 0;\n\n\tvoid decompose(std::vector <std::vector<std::size_t>>&\
    \ graph, const std::size_t& i)\n\t{\n\t\ttimes[i].first = currentTime++;\n\t\t\
    for(const auto& child : graph[i])\n\t\t{\n\t\t\tif(child != parent[i])\n\t\t\t\
    {\n\t\t\t\thead[child] = (graph[i][0] == child ? head[i] : child);\n\t\t\t\tdecompose(graph,\
    \ child);\n\t\t\t}\n\t\t}\n\t\ttimes[i].second = currentTime - 1;\n\t}\n\n\ttemplate<typename\
    \ F> void path(std::size_t u, std::size_t v, const F f)\n\t{\n\t\tfor(; head[u]\
    \ != head[v]; v = parent[head[v]])\n\t\t{\n\t\t\tif(depths[head[u]] > depths[head[v]])\n\
    \t\t\t{ std::swap(u, v); }\n\t\t\tf(times[head[v]].first, times[v].first);\n\t\
    \t}\n\t\tif(depths[u] > depths[v])\n\t\t{ std::swap(u, v); }\n\t\tf(times[u].first,\
    \ times[v].first);\n\t}\n\npublic:\n\texplicit HeavyLightDecomposition(std::vector\
    \ <std::vector<std::size_t>>& graph, const std::size_t& root = 0) : sizes(graph.size()),\
    \ parent(graph.size()), depths(graph.size()), head(graph.size()), times(graph.size()),\
    \ tree{graph.size()}\n\t{\n\t\tparent[root] = root;\n\t\tdepths[root] = 0;\n\t\
    \tdfs(graph, root);\n\t\thead[root] = root;\n\t\tdecompose(graph, root);\n\t}\n\
    \n\ttemplate<typename Iterable> void build(const Iterable& elements)\n\t{\n\t\t\
    Iterable positionedElements(elements.size());\n\t\tfor(std::size_t i = 0; i <\
    \ positionedElements.size(); ++i)\n\t\t{ positionedElements[times[i].first] =\
    \ elements[i]; }\n\t\ttree.build(positionedElements);\n\t}\n\n\ttemplate<typename...\
    \ Arguments> void update_sub_tree(const std::size_t& i, const Arguments& ... rest)\
    \ { tree.change(times[i].first, times[i].second, rest...); }\n\n\ttemplate<typename...\
    \ Arguments> void update_path(std::size_t u, std::size_t v, const Arguments& ...\
    \ rest)\n\t{\n\t\tpath(u, v, [this, &rest...](const std::size_t& low, const std::size_t&\
    \ high)\n\t\t{ tree.change(low, high, rest...); });\n\t}\n\n\tauto range(const\
    \ std::size_t& i) { return tree.range(times[i].first, times[i].second); }\n\n\t\
    auto range(const std::size_t& u, const std::size_t& v)\n\t{\n\t\tauto result{tree.f.identity};\n\
    \t\tpath(u, v, [this, &result](const std::size_t& left, const std::size_t& right)\n\
    \t\t{ result = tree.f.merge(result, tree.range(left, right)); });\n\t\treturn\
    \ tree.f.return_value(result);\n\t}\n};\n\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/heavy_light_decomposition.hpp
  requiredBy: []
  timestamp: '2021-05-06 17:00:48-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/heavy_light_decomposition.hpp
layout: document
redirect_from:
- /library/library/graph/heavy_light_decomposition.hpp
- /library/library/graph/heavy_light_decomposition.hpp.html
title: library/graph/heavy_light_decomposition.hpp
---
