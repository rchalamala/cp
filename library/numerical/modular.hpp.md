---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1261/submission/65632855
    - https://codeforces.com/contest/585/submission/24552744/
    - https://cp-algorithms.com/algebra/module-inverse.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: gcd.hpp: line\
    \ -1: no such header\n"
  code: "#ifndef MODULAR_HPP\n#define MODULAR_HPP\n\n// https://codeforces.com/contest/585/submission/24552744/\n\
    // https://codeforces.com/contest/1261/submission/65632855\n// https://cp-algorithms.com/algebra/module-inverse.html\n\
    // Verification:\n//\n\n#include <cassert>\n#include <cstddef>\n#include <cstdint>\n\
    #include <string>\n#include <type_traits>\n#include <vector>\n\n#include \"gcd.hpp\"\
    \n\ntemplate<class T> class Modular\n{\n\tusing Type = typename std::decay<decltype(T::value)>::type;\n\
    \n\tType value{};\n\npublic:\n\ttemplate<typename T1> Modular(const T1& element)\
    \ : value{normalize(element)}\n\t{\n\t\tstatic_assert(std::is_integral<T>::value);\n\
    \t\tstatic_assert(std::is_signed<T>::value);\n\t}\n\n\tconst Type& operator()()\
    \ const\n\t{\n\t\treturn value;\n\t}\n\n\ttemplate<typename T1> explicit operator\
    \ T1() const\n\t{\n\t\treturn static_cast<T1>(value);\n\t}\n\n\tconstexpr static\
    \ Type modulus()\n\t{\n\t\treturn T::value;\n\t}\n\n\ttemplate<typename T1> static\
    \ Type normalize(const T1& element)\n\t{\n\t\tType result{-modulus() <= element\
    \ && element < modulus() ? static_cast<Type>(element) : static_cast<Type>(element\
    \ % modulus())};\n\t\tif(result < 0)\n\t\t{ result += modulus(); }\n\t\treturn\
    \ result;\n\t}\n\n\tModular& operator+=(const Modular& other)\n\t{\n\t\tif((value\
    \ += other()) >= modulus())\n\t\t{ value -= modulus(); }\n\t\treturn *this;\n\t\
    }\n\n\ttemplate<typename T1> Modular& operator+=(const T1& other)\n\t{\n\t\treturn\
    \ *this += Modular(other);\n\t}\n\n\tModular& operator-=(const Modular& other)\n\
    \t{\n\t\tif((value -= other()) < 0)\n\t\t{ value += modulus(); }\n\t\treturn *this;\n\
    \t}\n\n\ttemplate<typename T1> Modular& operator-=(const T1& other)\n\t{\n\t\t\
    return *this -= Modular(other);\n\t}\n\n\tModular operator-() const\n\t{\n\t\t\
    return Modular(-value);\n\t}\n\n\ttemplate<typename T1 = T> typename std::enable_if<(sizeof(typename\
    \ Modular<T1>::Type) >= 8), Modular&>::type& operator*=(const Modular& rhs)\n\t\
    {\n\t\tstatic_assert(sizeof(T1) >= 8);\n\t\tauto quotient = static_cast<typename\
    \ Modular<T1>::Type>(\n\t\t\t\tstatic_cast<long double>(value) * rhs.value / modulus());\n\
    \t\tvalue = normalize(value * rhs.value - quotient * modulus());\n\t\treturn *this;\n\
    \t}\n\n\ttemplate<typename T1 = T> typename std::enable_if<(sizeof(typename Modular<T1>::Type)\
    \ < 8), Modular&>::type& operator*=(const Modular& rhs)\n\t{\n\t\tvalue = normalize<std::int64_t>(static_cast<std::int64_t>(value)\
    \ * rhs());\n\t\treturn *this;\n\t}\n\n\ttemplate<typename T1> Modular& operator*=(const\
    \ T1& other)\n\t{\n\t\treturn *this *= Modular(other);\n\t}\n\n\tModular& operator/=(const\
    \ Modular& other)\n\t{\n\t\treturn *this *= multiplicative_inverse(other());\n\
    \t}\n\n\ttemplate<typename T1> Modular& operator/=(const T1& other)\n\t{\n\t\t\
    return *this /= Modular(other);\n\t}\n\n\tModular& operator^=(const Modular& other)\n\
    \t{\n\t\tassert(other() >= 0);\n\t\tModular result(1);\n\t\tType exponent = other();\n\
    \t\twhile(exponent)\n\t\t{\n\t\t\tif(exponent % 2)\n\t\t\t{ result *= *this; }\n\
    \t\t\t*this *= *this;\n\t\t\texponent /= 2;\n\t\t}\n\t\treturn *this = result;\n\
    \t}\n\n\ttemplate<typename T1> Modular& operator^=(const T1& other)\n\t{\n\t\t\
    return *this ^= Modular(other);\n\t}\n\n\tModular& operator++()\n\t{\n\t\tif((*this\
    \ += 1) == modulus())\n\t\t{ *this = 0; }\n\t\treturn *this;\n\t}\n\n\tModular&\
    \ operator--()\n\t{\n\t\tif((*this -= 1) == -1)\n\t\t{ *this = modulus() - 1;\
    \ }\n\t\treturn *this;\n\t}\n\n\tModular operator++(int)\n\t{\n\t\tModular result(*this);\n\
    \t\t++(*this);\n\t\treturn result;\n\t}\n\n\tModular operator--(int)\n\t{\n\t\t\
    Modular result(*this);\n\t\t--(*this);\n\t\treturn result;\n\t}\n\n\tType multiplicative_inverse(const\
    \ Type& element)\n\t{\n\t\tauto gcd = extended_euclidian_gcd(normalize(element),\
    \ modulus());\n\t\tassert(std::get<2>(gcd) == 1);\n\t\treturn normalize(std::get<0>(gcd));\n\
    \t}\n\n\tstd::vector<Type> multiplicative_inverses(const Type& bound = modulus())\n\
    \t{\n\t\tassert(bound > 1);\n\t\tstd::vector<Type> inverses(bound);\n\t\tinverses[0]\
    \ = 0;\n\t\tinverses[1] = 1;\n\t\tfor(std::size_t i = 2; i < bound; ++i)\n\t\t\
    {\n\t\t\tinverses[i] = (modulus() - (modulus() / i) * inverses[modulus() % i]\
    \ % modulus()) % modulus();\n\t\t}\n\t\treturn inverses;\n\t}\n\n\ttemplate<typename\
    \ T1> friend std::istream& operator>>(std::istream&, Modular<T1>& element);\n\
    };\n\ntemplate<typename T> Modular<T> operator-(Modular<T> lhs, const Modular<T>&\
    \ rhs)\n{\n\treturn lhs -= rhs;\n}\n\ntemplate<typename T1, typename T2> Modular<T1>\
    \ operator-(Modular<T1> lhs, const T2& rhs)\n{\n\treturn lhs -= rhs;\n}\n\ntemplate<typename\
    \ T1, typename T2> Modular<T1> operator-(const T2& lhs, Modular<T1> rhs)\n{\n\t\
    return rhs -= lhs;\n}\n\ntemplate<typename T> Modular<T> operator*(Modular<T>\
    \ lhs, const Modular<T>& rhs)\n{\n\treturn lhs *= rhs;\n}\n\ntemplate<typename\
    \ T1, typename T2> Modular<T1> operator*(Modular<T1> lhs, const T2& rhs)\n{\n\t\
    return lhs *= rhs;\n}\n\ntemplate<typename T1, typename T2> Modular<T1> operator*(const\
    \ T2& lhs, Modular<T1> rhs)\n{\n\treturn rhs *= lhs;\n}\n\ntemplate<typename T>\
    \ Modular<T> operator/(Modular<T> lhs, const Modular<T>& rhs)\n{\n\treturn lhs\
    \ /= rhs;\n}\n\ntemplate<typename T1, typename T2> Modular<T1> operator/(Modular<T1>\
    \ lhs, const T2& rhs)\n{\n\treturn lhs /= rhs;\n}\n\ntemplate<typename T1, typename\
    \ T2> Modular<T1> operator/(const T2& lhs, Modular<T1> rhs)\n{\n\treturn rhs /=\
    \ lhs;\n}\n\ntemplate<typename T> Modular<T> operator^(Modular<T> lhs, const Modular<T>&\
    \ rhs)\n{\n\treturn lhs ^= rhs;\n}\n\ntemplate<typename T1, typename T2> Modular<T1>\
    \ operator^(Modular<T1> lhs, const T2& rhs)\n{\n\treturn lhs ^= rhs;\n}\n\ntemplate<typename\
    \ T1, typename T2> Modular<T1> operator^(const T2& lhs, Modular<T1> rhs)\n{\n\t\
    return rhs ^= lhs;\n}\n\ntemplate<typename T> bool operator==(const Modular<T>&\
    \ lhs, const Modular<T>& rhs)\n{\n\treturn lhs() == rhs();\n}\n\ntemplate<typename\
    \ T1, typename T2> bool operator==(const Modular<T1>& lhs, T2 rhs)\n{\n\treturn\
    \ lhs == Modular<T1>(rhs);\n}\n\ntemplate<typename T1, typename T2> bool operator==(T2\
    \ lhs, const Modular<T1>& rhs)\n{\n\treturn Modular<T1>(lhs) == rhs;\n}\n\ntemplate<typename\
    \ T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs)\n{\n\treturn\
    \ !(lhs == rhs);\n}\n\ntemplate<typename T1, typename T2> bool operator!=(const\
    \ Modular<T1>& lhs, T2 rhs)\n{\n\treturn !(lhs == rhs);\n}\n\ntemplate<typename\
    \ T1, typename T2> bool operator!=(T2 lhs, const Modular<T1>& rhs)\n{\n\treturn\
    \ !(lhs == rhs);\n}\n\ntemplate<typename T> bool operator<(const Modular<T>& lhs,\
    \ const Modular<T>& rhs)\n{\n\treturn lhs() < rhs();\n}\n\ntemplate<typename T1,\
    \ typename T2> bool operator<(const Modular<T1>& lhs, T2 rhs)\n{\n\treturn lhs\
    \ < Modular<T1>(rhs);\n}\n\ntemplate<typename T1, typename T2> bool operator<(T2\
    \ lhs, const Modular<T1>& rhs)\n{\n\treturn Modular<T1>(lhs) < rhs;\n}\n\ntemplate<typename\
    \ T> bool operator>(const Modular<T>& lhs, const Modular<T>& rhs)\n{\n\treturn\
    \ lhs() > rhs();\n}\n\ntemplate<typename T1, typename T2> bool operator>(const\
    \ Modular<T1>& lhs, T2 rhs)\n{\n\treturn lhs > Modular<T1>(rhs);\n}\n\ntemplate<typename\
    \ T1, typename T2> bool operator>(T2 lhs, const Modular<T1>& rhs)\n{\n\treturn\
    \ Modular<T1>(lhs) > rhs;\n}\n\ntemplate<typename T> bool operator<=(const Modular<T>&\
    \ lhs, const Modular<T>& rhs)\n{\n\treturn !(lhs() > rhs());\n}\n\ntemplate<typename\
    \ T1, typename T2> bool operator<=(const Modular<T1>& lhs, T2 rhs)\n{\n\treturn\
    \ !(lhs > Modular<T1>(rhs));\n}\n\ntemplate<typename T1, typename T2> bool operator<=(T2\
    \ lhs, const Modular<T1>& rhs)\n{\n\treturn !(Modular<T1>(lhs) > rhs);\n}\n\n\
    template<typename T> bool operator>=(const Modular<T>& lhs, const Modular<T>&\
    \ rhs)\n{\n\treturn !(lhs() < rhs());\n}\n\ntemplate<typename T1, typename T2>\
    \ bool operator>=(const Modular<T1>& lhs, T2 rhs)\n{\n\treturn !(lhs < Modular<T1>(rhs));\n\
    }\n\ntemplate<typename T1, typename T2> bool operator>=(T2 lhs, const Modular<T1>&\
    \ rhs)\n{\n\treturn !(Modular<T1>(lhs) < rhs);\n}\n\nnamespace std\n{\n\ttemplate<typename\
    \ T> std::string to_string(const Modular<T>& number)\n\t{\n\t\treturn std::to_string(number());\n\
    \t}\n}  // namespace std\n\ntemplate<typename T> std::istream& operator>>(std::istream&\
    \ stream, Modular<T>& element)\n{\n\tstream >> element.value;\n\telement.value\
    \ = Modular<T>::normalize(element.value);\n\treturn stream;\n}\n\ntemplate<typename\
    \ T> std::ostream& operator<<(std::ostream& stream, const Modular<T>& element)\n\
    {\n\treturn stream << element();\n}\n\nusing ModulusType = std::int64_t;\n\nconstexpr\
    \ ModulusType MOD1 = static_cast<long long>(1000000007);\nconstexpr ModulusType\
    \ MOD2 = static_cast<long long>(998244353);\n\nstruct MODULUS\n{\n\tstatic ModulusType\
    \ value;\n};\nModulusType MODULUS::value;\nusing VariableModulus = Modular<MODULUS>;\n\
    \nstruct StaticModulus1\n{\n\tconstexpr static ModulusType value{MOD1};\n};\n\
    struct StaticModulus2\n{\n\tconstexpr static ModulusType value{MOD2};\n};\n\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/modular.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/modular.hpp
layout: document
redirect_from:
- /library/library/numerical/modular.hpp
- /library/library/numerical/modular.hpp.html
title: library/numerical/modular.hpp
---
