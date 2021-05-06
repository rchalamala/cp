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
  code: "#include \"../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <cstddef>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../library/graph/heavy_light_decomposition.hpp\"\n#include \"\
    ../../library/data_structures/segment_tree/segment_tree.hpp\"\n#include \"../../library/data_structures/segment_tree/segment_tree_functions/segment_tree_add.hpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::size_t n;\n\tstd::int32_t q;\n\tstd::cin\
    \ >> n >> q;\n\tstd::vector <std::uint64_t> a(n);\n\tfor(auto& ai : a)\n\t{ std::cin\
    \ >> ai; }\n\tstd::vector <std::vector<std::size_t>> graph(n);\n\tfor(std::size_t\
    \ i = 1; i < n; ++i)\n\t{\n\t\tstd::size_t p;\n\t\tstd::cin >> p;\n\t\tgraph[i].push_back(p);\n\
    \t\tgraph[p].push_back(i);\n\t}\n\tHeavyLightDecomposition<SegmentTree<Add<AddNode<std::uint64_t>>>>\
    \ hld(graph);\n\thld.build(a);\n\twhile(q--)\n\t{\n\t\tbool queryType;\n\t\tstd::cin\
    \ >> queryType;\n\t\tif(queryType)\n\t\t{\n\t\t\tstd::size_t u;\n\t\t\tstd::cin\
    \ >> u;\n\t\t\tstd::cout << hld.range(u) << '\\n';\n\t\t}\n\t\telse\n\t\t{\n\t\
    \t\tstd::size_t u;\n\t\t\tstd::uint64_t x;\n\t\t\tstd::cin >> u >> x;\n\t\t\t\
    hld.update_path(u, u, x);\n\t\t}\n\t}\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verification/graph/heavy_light_decomposition_subtree.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verification/graph/heavy_light_decomposition_subtree.test.cpp
layout: document
redirect_from:
- /verify/verification/graph/heavy_light_decomposition_subtree.test.cpp
- /verify/verification/graph/heavy_light_decomposition_subtree.test.cpp.html
title: verification/graph/heavy_light_decomposition_subtree.test.cpp
---
