---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\n# -*- coding: utf-8 -*-\n\nimport os\nimport re\n\
    \nSTYLE = 'google'\n\n\ndef comment_remover(text):\n    def replacer(match):\n\
    \        s = match.group(0)\n        if s.startswith('/'):\n            return\
    \ \" \"\n        else:\n            return s\n\n    pattern = re.compile(\n  \
    \      r'//.*?$|/\\*.*?\\*/|\\'(?:\\\\.|[^\\\\\\'])*\\'|\"(?:\\\\.|[^\\\\\"])*\"\
    ',\n        re.DOTALL | re.MULTILINE\n    )\n    return re.sub(pattern, replacer,\
    \ text)\n\n\ndef main():\n    os.system(\"clang-format -style=\" + STYLE + \"\
    \ -dump-config > .clang-format\")\n    os.system(\"clang-format -i -style=file\
    \ output/main.cpp\")\n    os.remove(\".clang-format\")\n    with open(\"output/main.cpp\"\
    , 'r+') as f:\n        text = comment_remover(f.read())\n        f.seek(0)\n \
    \       f.write(text)\n        f.truncate()\n\n\nif __name__ == '__main__':\n\
    \    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: reformat.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: reformat.py
layout: document
redirect_from:
- /library/reformat.py
- /library/reformat.py.html
title: reformat.py
---
