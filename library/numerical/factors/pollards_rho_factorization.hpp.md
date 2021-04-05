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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: unused.hpp: line\
    \ -1: no such header\n"
  code: "#ifndef POLLARDS_RHO_FACTORIZATION_HPP\n#define POLLARDS_RHO_FACTORIZATION_HPP\n\
    \n#include <algorithm>\n#include <type_traits>\n#include <vector>\n\n#include\
    \ \"../../general/base.hpp\"\n#include \"../../general/prng.hpp\"\n#include \"\
    ../primality/miller_rabin_primality_test.hpp\"\n#include \"../steins_gcd.hpp\"\
    \n\nnamespace factors\n{\n\ttemplate<typename T> T pollards_rho(const T& n)\n\t\
    {\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tstatic_assert(std::is_unsigned_v<T>);\n\
    \t\tassert(n >= 0);\n\t\tif((n & 1) ^ 1)\n\t\t{ return 2; }\n\t\tif(primality::miller_rabin(n))\n\
    \t\t{ return n; }\n\t\tauto f{[&n](const T& x, const T& c) -> T\n\t\t       {\
    \ return static_cast<T>((static_cast<unsigned __int128>(x) * x + c) % n);; }};\n\
    \t\tfor(T x0{getUID<T>(0, n - 1)};; x0 = getUID<T>(0, n - 1))\n\t\t{\n\t\t\tT\
    \ c = getUID<T>(0, n - 1), x{f(x0, c)}, y{f(x, c)};\n\t\t\twhile(true)\n\t\t\t\
    {\n\t\t\t\tT divisor{steins_gcd(std::max(x, y) - std::min(x, y), n)};\n\t\t\t\t\
    if(divisor == n)\n\t\t\t\t{ break; }\n\t\t\t\tif(divisor != 1)\n\t\t\t\t{ return\
    \ divisor; }\n\t\t\t\tx = f(x, c);\n\t\t\t\ty = f(f(y, c), c);\n\t\t\t}\n\t\t\
    }\n\t}\n\n\ttemplate<typename T> std::vector<T> pollards_rho_factorize(const T&\
    \ n)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\t\tassert(n >= 0);\n\t\t\
    if(n <= 1)\n\t\t{ return {}; }\n\t\tT factor{pollards_rho<T>(n)};\n\t\tif(n ==\
    \ factor)\n\t\t{ return std::vector<T>{n}; }\n\t\tstd::vector<T> original{pollards_rho_factorize(factor)},\
    \ divided{pollards_rho_factorize(n / factor)};\n\t\tstd::move(std::begin(divided),\
    \ std::end(divided), std::back_inserter(original));\n\t\treturn original;\n\t\
    }\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/factors/pollards_rho_factorization.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/factors/pollards_rho_factorization.hpp
layout: document
redirect_from:
- /library/library/numerical/factors/pollards_rho_factorization.hpp
- /library/library/numerical/factors/pollards_rho_factorization.hpp.html
title: library/numerical/factors/pollards_rho_factorization.hpp
---
