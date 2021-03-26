#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import os

C_CPP_EXTENSIONS = ('.c', '.cc', '.cpp', '.cxx', '.h', '.hh', '.hpp', 'hxx')
STYLE = 'google'


def main():
    os.system("clang-format -style=" + STYLE + " -dump-config > .clang-format")
    for dirpath, dirnames, filenames in os.walk(os.getcwd()):
        for filename in filenames:
            if filename.endswith(C_CPP_EXTENSIONS):
                os.system(
                    "clang-format -i -style=file " +
                    dirpath +
                    "/" +
                    filename)
    os.remove(".clang-format")


if __name__ == '__main__':
    main()
