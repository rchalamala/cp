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
  code: "#ifndef OPTIMIZED_RHO_FACTORIZATION_HPP\n#define OPTIMIZED_RHO_FACTORIZATION_HPP\n\
    \n#include <type_traits>\n#include <vector>\n\n#include \"../../general/base.hpp\"\
    \n#include \"../../general/prng.hpp\"\n#include \"../list_of_primes.hpp\"\n#include\
    \ \"../montgomery.hpp\"\n#include \"../primality/miller_rabin_primality_test.hpp\"\
    \n#include \"../steins_gcd.hpp\"\n#include \"../trailing_zero_bits.hpp\"\n\nnamespace\
    \ factors\n{\n\ttemplate<typename T> T optimized_rho(const T& n)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tassert(n >= 0);\n\t\tif(primality::miller_rabin(n, false))\n\t\t{ return n;\
    \ }\n\t\tauto f{[&n](const Montgomery& x, const T& c) -> Montgomery\n\t\t    \
    \   {\n\t\t\t       Montgomery result = x;\n\t\t\t       (result *= result);\n\
    \t\t\t       result.n += c;\n\t\t\t       if(result.n >= n)\n\t\t\t       { result.n\
    \ -= n; }\n\t\t\t       return result;\n\t\t       }};\n\t\tT factor, c{getUID<T>(0,\
    \ n - 1)};\n\t\tMontgomery x{getUID<T>(0, n - 1)}, y{f(x, c)}, product{1};\n\t\
    \tfor(T trials{}; trials % 128 || (factor = steins_gcd(product.value(), n)) ==\
    \ 1; x = f(x, c), y = f(f(y, c), c))\n\t\t{\n\t\t\tif(x.n == y.n)\n\t\t\t{\n\t\
    \t\t\tc = getUID<T>(0, n - 1);\n\t\t\t\tx = Montgomery(getUID<T>(0, n - 1));\n\
    \t\t\t\ty = f(x, c);\n\t\t\t}\n\t\t\tMontgomery combined{product};\n\t\t\tcombined\
    \ *= Montgomery{std::max(x.n, y.n) - std::min(x.n, y.n)};\n\t\t\tif(combined.n\
    \ && combined.n != product.n)\n\t\t\t{\n\t\t\t\t++trials;\n\t\t\t\tproduct = combined;\n\
    \t\t\t}\n\t\t}\n\t\treturn factor;\n\t}\n\n\ttemplate<typename T> std::vector<T>\
    \ optimized_rho_factorize(const T& n, const bool& checkBaseCases = true)\n\t{\n\
    \t\tstatic_assert(std::is_integral_v<T>);\n\t\tassert(n >= 0);\n\t\tif(n <= 1)\n\
    \t\t{ return {}; }\n\t\tif(checkBaseCases)\n\t\t{\n\t\t\tT start{n};\n\t\t\tstd::vector<T>\
    \ original{};\n\t\t\tfor(const auto& a : largePrimes)\n\t\t\t{\n\t\t\t\tif(a >\
    \ start)\n\t\t\t\t{ break; }\n\t\t\t\twhile(start % a == 0)\n\t\t\t\t{\n\t\t\t\
    \t\toriginal.push_back(a);\n\t\t\t\t\tstart /= a;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    std::vector<T> divided{optimized_rho_factorize(start, false)};\n\t\t\tstd::move(std::begin(divided),\
    \ std::end(divided), std::back_inserter(original));\n\t\t\treturn original;\n\t\
    \t}\n\t\tT factor = optimized_rho<T>(n);\n\t\tif(n == factor)\n\t\t{ return std::vector<T>{n};\
    \ }\n\t\tstd::vector<T> original{optimized_rho_factorize(factor, false)}, divided{optimized_rho_factorize(n\
    \ / factor, false)};\n\t\tstd::move(std::begin(divided), std::end(divided), std::back_inserter(original));\n\
    \t\treturn original;\n\t}\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/factors/optimized_rho_factorization.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/factors/optimized_rho_factorization.hpp
layout: document
redirect_from:
- /library/library/numerical/factors/optimized_rho_factorization.hpp
- /library/library/numerical/factors/optimized_rho_factorization.hpp.html
title: library/numerical/factors/optimized_rho_factorization.hpp
---
