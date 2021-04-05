---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_affine.test.cpp
    title: verification/data_structures/segment_tree_affine.test.cpp
  - icon: ':heavy_check_mark:'
    path: verification/data_structures/segment_tree_composite.test.cpp
    title: verification/data_structures/segment_tree_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp
  bundledCode: "#line 1 \"library/numerical/modular.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <type_traits>\n\ntemplate<typename T> T inverse(T a, T m)\n{\n\tif(a\
    \ == 1)\n\t{ return 1; }\n\tT u = 0, v = 1;\n\twhile(a != 0)\n\t{\n\t\tT t = m\
    \ / a;\n\t\tm -= t * a;\n\t\tstd::swap(a, m);\n\t\tu -= t * v;\n\t\tstd::swap(u,\
    \ v);\n\t}\n\treturn u;\n}\n\n// https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp\n\
    template<typename MODULUS, std::enable_if_t<std::is_integral_v<std::decay_t<decltype(MODULUS::value)>>\
    \ && std::is_signed_v<std::decay_t<decltype(MODULUS::value)>>, bool> = true> class\
    \ Modulo\n{\n\tusing Type = typename std::decay_t<decltype(MODULUS::value)>;\n\
    \n\tType value{};\n\n\ttemplate<typename T> static T normalize(const T& element)\n\
    \t{\n\t\tType result{};\n\t\tif(-modulus() < element && element < modulus())\n\
    \t\t{\n\t\t\tresult = element;\n\t\t}\n\t\tif(result < 0)\n\t\t{ result += modulus();\
    \ }\n\t\treturn result;\n\t}\n\npublic:\n\tconstexpr static Type modulus() { return\
    \ MODULUS::value; }\n\n\tModulo() {}\n\n\ttemplate<typename T> Modulo(const T&\
    \ uValue) : value{normalize(static_cast<Type>(uValue))} {}\n\n\tconst Type& operator()()\
    \ const { return value; }\n\n\ttemplate<typename T> explicit operator T() { return\
    \ static_cast<T>(value); }\n\n\tModulo operator-() const { return Modulo{modulus()\
    \ - value}; }\n\n\tModulo operator~() const { return Modulo{inverse(value, modulus())};\
    \ }\n\n\tModulo& operator++()\n\t{\n\t\tif(++value == modulus())\n\t\t{ value\
    \ = 0; }\n\t\treturn *this;\n\t}\n\n\tModulo& operator++(int)\n\t{\n\t\tModulo\
    \ result{*this};\n\t\t++*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator--()\n\
    \t{\n\t\tif(value == 0)\n\t\t{ value = modulus(); }\n\t\t--value;\n\t\treturn\
    \ *this;\n\t}\n\n\tModulo& operator--(int)\n\t{\n\t\tModulo result{*this};\n\t\
    \t--*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator+=(const Modulo& other)\n\
    \t{\n\t\tif((value -= (modulus() - other.value)) < 0)\n\t\t{ value += modulus();\
    \ }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator+=(const\
    \ T& other) { return *this += Modulo{other}; }\n\n\tModulo& operator-=(const Modulo&\
    \ other)\n\t{\n\t\tif((value -= other.value) < 0)\n\t\t{ value += modulus(); }\n\
    \t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator-=(const T& other)\
    \ { return *this -= Modulo{other}; }\n\n\tModulo& operator*=(const Modulo& other)\n\
    \t{\n\t\tvalue = static_cast<Type>(static_cast<std::int64_t>(value) * other.value\
    \ % modulus());\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator*=(const\
    \ T& other) { return *this *= Modulo{other}; }\n\n\tModulo& operator/=(const Modulo&\
    \ other) { return *this *= ~other; }\n\n\ttemplate<typename T> Modulo& operator/=(const\
    \ T& other) { return *this /= Modulo{other}; }\n\n\ttemplate<typename T> friend\
    \ bool operator==(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\ttemplate<typename\
    \ T> friend bool operator<(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\t\
    template<typename T> friend bool operator>(const Modulo<T>& lhs, const Modulo<T>&\
    \ rhs);\n\n\ttemplate<typename T> friend std::istream& operator>>(std::istream&\
    \ in, Modulo<T>& element);\n};\n\ntemplate<typename T> bool operator==(const Modulo<T>&\
    \ lhs, const Modulo<T>& rhs) { return lhs.value == rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator==(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs == Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator==(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} == rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator!=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ == rhs); }\n\ntemplate<typename T> bool operator<(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return lhs.value < rhs.value; }\ntemplate<typename T1, typename\
    \ T2> bool operator<(const Modulo<T1>& lhs, const T2& rhs) { return lhs < Modulo<T1>{rhs};\
    \ }\ntemplate<typename T1, typename T2> bool operator<(const T1& lhs, const Modulo<T2>&\
    \ rhs) { return Modulo<T2>{lhs} < rhs; }\n\ntemplate<typename T> bool operator>(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value > rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator>(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs > Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator>(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} > rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator<=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ > rhs); }\n\ntemplate<typename T1, typename T2> bool operator>=(const T1& lhs,\
    \ const T2& rhs) { return !(lhs < rhs); }\n\ntemplate<typename T> Modulo<T> operator+(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} += rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator+(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} += rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator+(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} +=\
    \ rhs; }\n\ntemplate<typename T> Modulo<T> operator-(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return Modulo<T>{lhs} -= rhs; }\ntemplate<typename T1, typename\
    \ T2> Modulo<T1> operator-(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs}\
    \ -= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2> operator-(const T1&\
    \ lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} -= rhs; }\n\ntemplate<typename\
    \ T> Modulo<T> operator*(const Modulo<T>& lhs, const Modulo<T>& rhs) { return\
    \ Modulo<T>{lhs} *= rhs; }\ntemplate<typename T1, typename T2> Modulo<T1> operator*(const\
    \ Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} *= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T2> operator*(const T1& lhs, const Modulo<T2>& rhs)\
    \ { return Modulo<T2>{lhs} *= rhs; }\n\ntemplate<typename T> Modulo<T> operator/(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} /= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator/(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} /= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator/(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} /=\
    \ rhs; }\n\ntemplate<typename T> std::istream& operator>>(std::istream& in, Modulo<T>&\
    \ element)\n{\n\tin >> element.value;\n\telement.value = Modulo<T>::normalize(element.value);\n\
    \treturn in;\n}\n\ntemplate<typename T> std::ostream& operator<<(std::ostream&\
    \ out, const Modulo<T>& element) { return out << element(); }\n\n// DIVISION AND\
    \ FIX UP GCD WHEN NOT LAZY AND STATIC ASSERTIONS\n\n\n"
  code: "#ifndef MODULAR_HPP\n#define MODULAR_HPP\n\n#include <algorithm>\n#include\
    \ <type_traits>\n\ntemplate<typename T> T inverse(T a, T m)\n{\n\tif(a == 1)\n\
    \t{ return 1; }\n\tT u = 0, v = 1;\n\twhile(a != 0)\n\t{\n\t\tT t = m / a;\n\t\
    \tm -= t * a;\n\t\tstd::swap(a, m);\n\t\tu -= t * v;\n\t\tstd::swap(u, v);\n\t\
    }\n\treturn u;\n}\n\n// https://github.com/the-tourist/algo/blob/master/numeric/mint.cpp\n\
    template<typename MODULUS, std::enable_if_t<std::is_integral_v<std::decay_t<decltype(MODULUS::value)>>\
    \ && std::is_signed_v<std::decay_t<decltype(MODULUS::value)>>, bool> = true> class\
    \ Modulo\n{\n\tusing Type = typename std::decay_t<decltype(MODULUS::value)>;\n\
    \n\tType value{};\n\n\ttemplate<typename T> static T normalize(const T& element)\n\
    \t{\n\t\tType result{};\n\t\tif(-modulus() < element && element < modulus())\n\
    \t\t{\n\t\t\tresult = element;\n\t\t}\n\t\tif(result < 0)\n\t\t{ result += modulus();\
    \ }\n\t\treturn result;\n\t}\n\npublic:\n\tconstexpr static Type modulus() { return\
    \ MODULUS::value; }\n\n\tModulo() {}\n\n\ttemplate<typename T> Modulo(const T&\
    \ uValue) : value{normalize(static_cast<Type>(uValue))} {}\n\n\tconst Type& operator()()\
    \ const { return value; }\n\n\ttemplate<typename T> explicit operator T() { return\
    \ static_cast<T>(value); }\n\n\tModulo operator-() const { return Modulo{modulus()\
    \ - value}; }\n\n\tModulo operator~() const { return Modulo{inverse(value, modulus())};\
    \ }\n\n\tModulo& operator++()\n\t{\n\t\tif(++value == modulus())\n\t\t{ value\
    \ = 0; }\n\t\treturn *this;\n\t}\n\n\tModulo& operator++(int)\n\t{\n\t\tModulo\
    \ result{*this};\n\t\t++*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator--()\n\
    \t{\n\t\tif(value == 0)\n\t\t{ value = modulus(); }\n\t\t--value;\n\t\treturn\
    \ *this;\n\t}\n\n\tModulo& operator--(int)\n\t{\n\t\tModulo result{*this};\n\t\
    \t--*this;\n\t\treturn result;\n\t}\n\n\tModulo& operator+=(const Modulo& other)\n\
    \t{\n\t\tif((value -= (modulus() - other.value)) < 0)\n\t\t{ value += modulus();\
    \ }\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator+=(const\
    \ T& other) { return *this += Modulo{other}; }\n\n\tModulo& operator-=(const Modulo&\
    \ other)\n\t{\n\t\tif((value -= other.value) < 0)\n\t\t{ value += modulus(); }\n\
    \t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator-=(const T& other)\
    \ { return *this -= Modulo{other}; }\n\n\tModulo& operator*=(const Modulo& other)\n\
    \t{\n\t\tvalue = static_cast<Type>(static_cast<std::int64_t>(value) * other.value\
    \ % modulus());\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T> Modulo& operator*=(const\
    \ T& other) { return *this *= Modulo{other}; }\n\n\tModulo& operator/=(const Modulo&\
    \ other) { return *this *= ~other; }\n\n\ttemplate<typename T> Modulo& operator/=(const\
    \ T& other) { return *this /= Modulo{other}; }\n\n\ttemplate<typename T> friend\
    \ bool operator==(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\ttemplate<typename\
    \ T> friend bool operator<(const Modulo<T>& lhs, const Modulo<T>& rhs);\n\n\t\
    template<typename T> friend bool operator>(const Modulo<T>& lhs, const Modulo<T>&\
    \ rhs);\n\n\ttemplate<typename T> friend std::istream& operator>>(std::istream&\
    \ in, Modulo<T>& element);\n};\n\ntemplate<typename T> bool operator==(const Modulo<T>&\
    \ lhs, const Modulo<T>& rhs) { return lhs.value == rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator==(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs == Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator==(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} == rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator!=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ == rhs); }\n\ntemplate<typename T> bool operator<(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return lhs.value < rhs.value; }\ntemplate<typename T1, typename\
    \ T2> bool operator<(const Modulo<T1>& lhs, const T2& rhs) { return lhs < Modulo<T1>{rhs};\
    \ }\ntemplate<typename T1, typename T2> bool operator<(const T1& lhs, const Modulo<T2>&\
    \ rhs) { return Modulo<T2>{lhs} < rhs; }\n\ntemplate<typename T> bool operator>(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return lhs.value > rhs.value; }\ntemplate<typename\
    \ T1, typename T2> bool operator>(const Modulo<T1>& lhs, const T2& rhs) { return\
    \ lhs > Modulo<T1>{rhs}; }\ntemplate<typename T1, typename T2> bool operator>(const\
    \ T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} > rhs; }\n\ntemplate<typename\
    \ T1, typename T2> bool operator<=(const T1& lhs, const T2& rhs) { return !(lhs\
    \ > rhs); }\n\ntemplate<typename T1, typename T2> bool operator>=(const T1& lhs,\
    \ const T2& rhs) { return !(lhs < rhs); }\n\ntemplate<typename T> Modulo<T> operator+(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} += rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator+(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} += rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator+(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} +=\
    \ rhs; }\n\ntemplate<typename T> Modulo<T> operator-(const Modulo<T>& lhs, const\
    \ Modulo<T>& rhs) { return Modulo<T>{lhs} -= rhs; }\ntemplate<typename T1, typename\
    \ T2> Modulo<T1> operator-(const Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs}\
    \ -= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2> operator-(const T1&\
    \ lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} -= rhs; }\n\ntemplate<typename\
    \ T> Modulo<T> operator*(const Modulo<T>& lhs, const Modulo<T>& rhs) { return\
    \ Modulo<T>{lhs} *= rhs; }\ntemplate<typename T1, typename T2> Modulo<T1> operator*(const\
    \ Modulo<T1>& lhs, const T2& rhs) { return Modulo<T1>{lhs} *= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T2> operator*(const T1& lhs, const Modulo<T2>& rhs)\
    \ { return Modulo<T2>{lhs} *= rhs; }\n\ntemplate<typename T> Modulo<T> operator/(const\
    \ Modulo<T>& lhs, const Modulo<T>& rhs) { return Modulo<T>{lhs} /= rhs; }\ntemplate<typename\
    \ T1, typename T2> Modulo<T1> operator/(const Modulo<T1>& lhs, const T2& rhs)\
    \ { return Modulo<T1>{lhs} /= rhs; }\ntemplate<typename T1, typename T2> Modulo<T2>\
    \ operator/(const T1& lhs, const Modulo<T2>& rhs) { return Modulo<T2>{lhs} /=\
    \ rhs; }\n\ntemplate<typename T> std::istream& operator>>(std::istream& in, Modulo<T>&\
    \ element)\n{\n\tin >> element.value;\n\telement.value = Modulo<T>::normalize(element.value);\n\
    \treturn in;\n}\n\ntemplate<typename T> std::ostream& operator<<(std::ostream&\
    \ out, const Modulo<T>& element) { return out << element(); }\n\n// DIVISION AND\
    \ FIX UP GCD WHEN NOT LAZY AND STATIC ASSERTIONS\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/modular.hpp
  requiredBy: []
  timestamp: '2021-04-05 00:55:31-06:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verification/data_structures/segment_tree_affine.test.cpp
  - verification/data_structures/segment_tree_composite.test.cpp
documentation_of: library/numerical/modular.hpp
layout: document
redirect_from:
- /library/library/numerical/modular.hpp
- /library/library/numerical/modular.hpp.html
title: library/numerical/modular.hpp
---
