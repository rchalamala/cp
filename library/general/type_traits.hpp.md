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
  bundledCode: "#line 1 \"library/general/type_traits.hpp\"\n\n\n\n#include <type_traits>\n\
    #include <utility>\n\ntemplate<tyename T> class IsIterable\n{\n\ttemplate<typename\
    \ U> static auto begin(int) -> decltype(std::declval<U>.begin() == 1, std::true_type());\n\
    \n\ttemplate<typename U> static auto end(int) -> decltype(std::declval<U>.end()\
    \ == 1, std::true_type());\n\n\ttemplate<typename U> static auto end(int) -> decltype(std::declval<U>.end()\
    \ == 1, std::true_type());\n\n\ttemplate<typename> static std::false_type begin(...);\n\
    \n\ttemplate<typename> static std::false_type end(...);\n\npublic:\n\n\tstatic\
    \ constexpr bool value{std::is_same<decltype(begin<T>(0)), decltype(end<T>(0)),\
    \ std::true_type>::value};\n};\n\n\n"
  code: "#ifndef TYPE_TRAITS_HPP\n#define TYPE_TRAITS_HPP\n\n#include <type_traits>\n\
    #include <utility>\n\ntemplate<tyename T> class IsIterable\n{\n\ttemplate<typename\
    \ U> static auto begin(int) -> decltype(std::declval<U>.begin() == 1, std::true_type());\n\
    \n\ttemplate<typename U> static auto end(int) -> decltype(std::declval<U>.end()\
    \ == 1, std::true_type());\n\n\ttemplate<typename U> static auto end(int) -> decltype(std::declval<U>.end()\
    \ == 1, std::true_type());\n\n\ttemplate<typename> static std::false_type begin(...);\n\
    \n\ttemplate<typename> static std::false_type end(...);\n\npublic:\n\n\tstatic\
    \ constexpr bool value{std::is_same<decltype(begin<T>(0)), decltype(end<T>(0)),\
    \ std::true_type>::value};\n};\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/general/type_traits.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/type_traits.hpp
layout: document
redirect_from:
- /library/library/general/type_traits.hpp
- /library/library/general/type_traits.hpp.html
title: library/general/type_traits.hpp
---
