#!/bin/bash
#
# clang-format-all.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

PROJECT_ROOT=$(git rev-parse --show-toplevel)
CLANG_FORMAT="$PROJECT_ROOT/tools/clang-format"

cd $PROJECT_ROOT

find src test ! -path 'test/catch.hpp' \
  \( -name '*.cpp' -or -name '*.hpp' -or -name '*.c' -or -name '*.h' \) \
  | xargs -I% $CLANG_FORMAT -style=Google -i %
