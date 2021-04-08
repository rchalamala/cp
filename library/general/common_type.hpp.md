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
  bundledCode: '#line 1 "library/general/common_type.hpp"




    #include <algorithm>


    template<typename T1, typename T2> std::common_type_t<T1, T2> static min(const
    T1& lhs, const T2& rhs) { return std::min(static_cast<std::common_type_t<T1, T2>>(lhs),
    static_cast<std::common_type_t<T1, T2>>(rhs)); }


    template<typename T1, typename T2> std::common_type_t<T1, T2> static max(const
    T1& lhs, const T2& rhs) { return std::max(static_cast<std::common_type_t<T1, T2>>(lhs),
    static_cast<std::common_type_t<T1, T2>>(rhs)); }



    '
  code: '#ifndef COMMON_TYPE_HPP

    #define COMMON_TYPE_HPP


    #include <algorithm>


    template<typename T1, typename T2> std::common_type_t<T1, T2> static min(const
    T1& lhs, const T2& rhs) { return std::min(static_cast<std::common_type_t<T1, T2>>(lhs),
    static_cast<std::common_type_t<T1, T2>>(rhs)); }


    template<typename T1, typename T2> std::common_type_t<T1, T2> static max(const
    T1& lhs, const T2& rhs) { return std::max(static_cast<std::common_type_t<T1, T2>>(lhs),
    static_cast<std::common_type_t<T1, T2>>(rhs)); }


    #endif'
  dependsOn: []
  isVerificationFile: false
  path: library/general/common_type.hpp
  requiredBy: []
  timestamp: '2021-04-07 22:54:37-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/common_type.hpp
layout: document
redirect_from:
- /library/library/general/common_type.hpp
- /library/library/general/common_type.hpp.html
title: library/general/common_type.hpp
---
