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
  bundledCode: "#line 1 \"library/string/tokenize.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <regex>\n#include <string>\n#include <vector>\n\nstd::vector<std::string>\
    \ tokenize(const std::string& input, const std::regex& pattern = std::regex{R\"\
    ([\\\\s|\\\\h|,]+)\"})\n{\n\tstd::vector<std::string> tokens{std::sregex_token_iterator{input.begin(),\
    \ input.end(), pattern, -1}, {}};\n\ttokens.erase(std::remove_if(tokens.begin(),\
    \ tokens.end(), [](const std::string& token) -> bool\n\t{ return token.size()\
    \ == 0; }), tokens.end());\n\treturn tokens;\n}\n\n\n"
  code: "#ifndef TOKENIZE_HPP\n#define TOKENIZE_HPP\n\n#include <algorithm>\n#include\
    \ <regex>\n#include <string>\n#include <vector>\n\nstd::vector<std::string> tokenize(const\
    \ std::string& input, const std::regex& pattern = std::regex{R\"([\\\\s|\\\\h|,]+)\"\
    })\n{\n\tstd::vector<std::string> tokens{std::sregex_token_iterator{input.begin(),\
    \ input.end(), pattern, -1}, {}};\n\ttokens.erase(std::remove_if(tokens.begin(),\
    \ tokens.end(), [](const std::string& token) -> bool\n\t{ return token.size()\
    \ == 0; }), tokens.end());\n\treturn tokens;\n}\n\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/string/tokenize.hpp
  requiredBy: []
  timestamp: '2021-04-23 11:05:35-06:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/string/tokenize.hpp
layout: document
redirect_from:
- /library/library/string/tokenize.hpp
- /library/library/string/tokenize.hpp.html
title: library/string/tokenize.hpp
---
