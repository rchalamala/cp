#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os
import re

STYLE = 'google'


def comment_remover(text):
    def replacer(match):
        s = match.group(0)
        if s.startswith('/'):
            return " "
        else:
            return s

    pattern = re.compile(
        r'//.*?$|/\*.*?\*/|\'(?:\\.|[^\\\'])*\'|"(?:\\.|[^\\"])*"',
        re.DOTALL | re.MULTILINE
    )
    return re.sub(pattern, replacer, text)


def main():
    os.system("clang-format -style=" + STYLE + " -dump-config > .clang-format")
    os.system("clang-format -i -style=file output/main.cpp")
    os.remove(".clang-format")
    with open("output/main.cpp", 'r+') as f:
        text = comment_remover(f.read())
        f.seek(0)
        f.write(text)
        f.truncate()


if __name__ == '__main__':
    main()
