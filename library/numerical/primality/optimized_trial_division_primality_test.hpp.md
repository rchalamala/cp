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
  bundledCode: "#line 1 \"library/numerical/primality/optimized_trial_division_primality_test.hpp\"\
    \n\n\n\nnamespace primality\n{\n\ttemplate<typename T> bool optimized_trial_division(const\
    \ T& n)\n\t{\n\t\tstatic_assert(std::is_integral_v < T > );\n\t\tif(n <= 1)\n\t\
    \t{ return false; }\n\t\tif(n <= 3)\n\t\t{ return true; }\n\t\tif(n % 2 == 0 ||\
    \ n % 3 == 0)\n\t\t{ return false; }\n\t\tfor(T i = 5; i * i <= n; i += 6)\n\t\
    \t{\n\t\t\tif(n % i == 0)\n\t\t\t{ return false; }\n\t\t\tif(n % (i + 2) == 0)\n\
    \t\t\t{ return false; }\n\t\t}\n\t\treturn true;\n\t}\n}\n\n\n"
  code: "#ifndef OPTIMIZED_TRIAL_DIVISION_PRIMALITY_TEST_HPP\n#define OPTIMIZED_TRIAL_DIVISION_PRIMALITY_TEST_HPP\n\
    \nnamespace primality\n{\n\ttemplate<typename T> bool optimized_trial_division(const\
    \ T& n)\n\t{\n\t\tstatic_assert(std::is_integral_v < T > );\n\t\tif(n <= 1)\n\t\
    \t{ return false; }\n\t\tif(n <= 3)\n\t\t{ return true; }\n\t\tif(n % 2 == 0 ||\
    \ n % 3 == 0)\n\t\t{ return false; }\n\t\tfor(T i = 5; i * i <= n; i += 6)\n\t\
    \t{\n\t\t\tif(n % i == 0)\n\t\t\t{ return false; }\n\t\t\tif(n % (i + 2) == 0)\n\
    \t\t\t{ return false; }\n\t\t}\n\t\treturn true;\n\t}\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/primality/optimized_trial_division_primality_test.hpp
  requiredBy: []
  timestamp: '2021-03-25 17:23:26-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/primality/optimized_trial_division_primality_test.hpp
layout: document
redirect_from:
- /library/library/numerical/primality/optimized_trial_division_primality_test.hpp
- /library/library/numerical/primality/optimized_trial_division_primality_test.hpp.html
title: library/numerical/primality/optimized_trial_division_primality_test.hpp
---
