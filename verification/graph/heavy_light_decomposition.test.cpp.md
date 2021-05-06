---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.5/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../library/general/speed.hpp:\
    \ line -1: no such header\n"
  code: "#include \"../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://www.hackerrank.com/challenges/subtrees-and-paths/problem\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../library/graph/heavy_light_decomposition.hpp\"\n#include \"\
    ../../library/data_structures/segment_tree/segment_tree.hpp\"\n#include \"../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_maximum.hpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::size_t n;\n\tstd::cin >> n;\n\tstd::vector\
    \ <std::vector<std::size_t>> graph(n);\n\tfor(std::size_t i = 1; i < n; ++i)\n\
    \t{\n\t\tstd::size_t u, v;\n\t\tstd::cin >> u >> v;\n\t\t--u;\n\t\t--v;\n\t\t\
    graph[u].push_back(v);\n\t\tgraph[v].push_back(u);\n\t}\n\tHeavyLightDecomposition<SegmentTree<Maximum<MaximumNode<std::int64_t>>>>\
    \ hld(graph);\n\tstd::int32_t q;\n\tstd::cin >> q;\n\twhile(q--)\n\t{\n\t\tstd::string\
    \ queryType;\n\t\tstd::cin >> queryType;\n\t\tif(queryType == \"add\")\n\t\t{\n\
    \t\t\tstd::size_t t;\n\t\t\tstd::int64_t value;\n\t\t\tstd::cin >> t >> value;\n\
    \t\t\thld.update_sub_tree(t - 1, value);\n\t\t}\n\t\telse\n\t\t{\n\t\t\tstd::size_t\
    \ a, b;\n\t\t\tstd::cin >> a >> b;\n\t\t\tstd::cout << hld.range(a - 1, b - 1)\
    \ << '\\n';\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verification/graph/heavy_light_decomposition.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verification/graph/heavy_light_decomposition.test.cpp
layout: document
redirect_from:
- /verify/verification/graph/heavy_light_decomposition.test.cpp
- /verify/verification/graph/heavy_light_decomposition.test.cpp.html
title: verification/graph/heavy_light_decomposition.test.cpp
---