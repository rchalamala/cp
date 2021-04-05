---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: unused.hpp: line\
    \ -1: no such header\n"
  code: "#include \"../../../library/general/input.hpp\"\n#include \"../../../library/general/output.hpp\"\
    \n#include \"../../../library/general/speed.hpp\"\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
    \n\n#include <algorithm>\n#include <cstdint>\n#include <iostream>\n#include <vector>\n\
    \n#include \"../../../library/numerical/factors/optimized_rho_factorization.hpp\"\
    \n\nint main()\n{\n\tspeed();\n\tstd::int_fast16_t q;\n\tread(std::cin, q);\n\t\
    while(q--)\n\t{\n\t\tstd::uint64_t a;\n\t\tread(std::cin, a);\n\t\tstd::vector<std::uint64_t>\
    \ factors = factors::optimized_rho_factorize<std::uint64_t>(a);\n\t\tstd::sort(std::begin(factors),\
    \ std::end(factors));\n\t\tprints(std::cout, std::size(factors), factors);\n\t\
    }\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: verification/numerical/factors/optimized_rho_factorization.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verification/numerical/factors/optimized_rho_factorization.test.cpp
layout: document
redirect_from:
- /verify/verification/numerical/factors/optimized_rho_factorization.test.cpp
- /verify/verification/numerical/factors/optimized_rho_factorization.test.cpp.html
title: verification/numerical/factors/optimized_rho_factorization.test.cpp
---
