#!/bin/bash
#
# clang-format-all.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

find src test ! -path 'test/catch.hpp' \
  \( -name '*.cpp' -or -name '*.hpp' -or -name '*.c' -or -name '*.h' \) \
  | xargs -I% clang-format -i %
