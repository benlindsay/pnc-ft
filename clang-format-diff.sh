#!/bin/bash
#
# clang-format-diff.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

file_list=$( find src test ! -path 'test/catch.hpp' \
  \( -name '*.cpp' -or -name '*.hpp' -or -name '*.c' -or -name '*.h' \) \
)

# Show the changes made by diffing all source files except catch.hpp.
# Failing exit code if any changes are made.

diff -u <(cat $file_list) <(clang-format $file_list)
