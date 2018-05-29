#!/bin/bash
#
# clang-format-diff.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

PROJECT_ROOT=$(git rev-parse --show-toplevel)
CLANG_FORMAT="$PROJECT_ROOT/tools/clang-format"

cd $PROJECT_ROOT

file_list=$( find src test ! -path 'test/catch.hpp' \
  \( -name '*.cpp' -or -name '*.hpp' -or -name '*.c' -or -name '*.h' \) \
)

# Show the changes made by diffing all source files except catch.hpp.
# Failing exit code if any changes are made.

diff -u <(cat $file_list) <($CLANG_FORMAT -style=Google $file_list)
