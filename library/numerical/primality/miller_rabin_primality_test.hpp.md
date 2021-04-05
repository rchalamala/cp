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
  code: "#ifndef MILLER_RABIN_PRIMALITY_TEST_HPP\n#define MILLER_RABIN_PRIMALITY_TEST_HPP\n\
    \n#include <limits>\n#include <type_traits>\n#include <vector>\n\n#include \"\
    ../../general/base.hpp\"\n#include \"../list_of_primes.hpp\"\n#include \"../montgomery.hpp\"\
    \n#include \"../trailing_zero_bits.hpp\"\n\nnamespace primality\n{\n\n\ttemplate<typename\
    \ T> Montgomery power(const Montgomery& base, T exponent)\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tstatic_assert(std::is_unsigned_v<T>);\n\t\tMontgomery mBase = base, result(1);\n\
    \t\twhile(exponent)\n\t\t{\n\t\t\tif(exponent & 1)\n\t\t\t{ result *= mBase; }\n\
    \t\t\tmBase *= mBase;\n\t\t\texponent >>= 1;\n\t\t}\n\t\treturn result;\n\t}\n\
    \n\ttemplate<typename T, std::size_t BasesSize = 7> bool miller_rabin(const T&\
    \ n, const bool& checkBaseCases = true, const std::array<T, BasesSize>& A = {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022})\n\t{\n\t\tstatic_assert(std::is_integral_v<T>);\n\
    \t\tstatic_assert(std::is_unsigned_v<T>);\n\t\tif(checkBaseCases)\n\t\t{\n\t\t\
    \tif(n <= 1)\n\t\t\t{ return false; }\n\t\t\tfor(const auto& a : largePrimes)\n\
    \t\t\t{\n\t\t\t\tif(a > n)\n\t\t\t\t{ break; }\n\t\t\t\tif(n == a)\n\t\t\t\t{\n\
    \t\t\t\t\treturn true;\n\t\t\t\t}\n\t\t\t\tif(n % a == 0)\n\t\t\t\t{ return false;\
    \ }\n\t\t\t}\n\t\t}\n\t\tif(Montgomery::modulus != n)\n\t\t{ Montgomery::set_modulus(n);\
    \ }\n\t\tT bits{trailing_zero_bits(n - 1)}, d{(n - 1) >> bits};\n\t\tMontgomery\
    \ one{1}, negativeOne{n - 1};\n\t\tfor(const T& a : A)\n\t\t{\n\t\t\tMontgomery\
    \ mA{a};\n\t\t\tif(mA.n)\n\t\t\t{\n\t\t\t\tT i{};\n\t\t\t\tMontgomery x{power(mA,\
    \ d)};\n\t\t\t\tif(x.n == one.n || x.n == negativeOne.n)\n\t\t\t\t{ continue;\
    \ }\n\t\t\t\tfor(; x.n != one.n && x.n != negativeOne.n && i < bits; ++i)\n\t\t\
    \t\t{\n\t\t\t\t\tif(x.n == one.n)\n\t\t\t\t\t{ return false; }\n\t\t\t\t\tif(x.n\
    \ == negativeOne.n)\n\t\t\t\t\t{ break; }\n\t\t\t\t\tx *= x;\n\t\t\t\t}\n\t\t\t\
    \tif((i == bits) ^ (x.n == one.n))\n\t\t\t\t{ return false; }\n\t\t\t}\n\t\t\t\
    else\n\t\t\t{ return true; }\n\t\t}\n\t\treturn true;\n\t}\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/primality/miller_rabin_primality_test.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/primality/miller_rabin_primality_test.hpp
layout: document
redirect_from:
- /library/library/numerical/primality/miller_rabin_primality_test.hpp
- /library/library/numerical/primality/miller_rabin_primality_test.hpp.html
title: library/numerical/primality/miller_rabin_primality_test.hpp
---
