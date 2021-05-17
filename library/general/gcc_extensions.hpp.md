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
  bundledCode: '#line 1 "library/general/gcc_extensions.hpp"




    #ifdef __GNUC__


    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    #include <ext/rope>


    using namespace __gnu_pbds;

    using namespace __gnu_cxx;


    template<typename T> using orderedSet = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

    template<typename T> using orderedMultiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


    #endif



    '
  code: '#ifndef GCC_EXTENSIONS_HPP

    #define GCC_EXTENSIONS_HPP


    #ifdef __GNUC__


    #include <ext/pb_ds/assoc_container.hpp>

    #include <ext/pb_ds/tree_policy.hpp>

    #include <ext/rope>


    using namespace __gnu_pbds;

    using namespace __gnu_cxx;


    template<typename T> using orderedSet = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

    template<typename T> using orderedMultiset = __gnu_pbds::tree<T, __gnu_pbds::null_type,
    std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;


    #endif


    #endif'
  dependsOn: []
  isVerificationFile: false
  path: library/general/gcc_extensions.hpp
  requiredBy: []
  timestamp: '2021-05-06 17:00:48-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/general/gcc_extensions.hpp
layout: document
redirect_from:
- /library/library/general/gcc_extensions.hpp
- /library/library/general/gcc_extensions.hpp.html
title: library/general/gcc_extensions.hpp
---
