#!/bin/bash
#
# install-yaml-cpp.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

YAML_CPP=/tmp/yaml-cpp
PROJECT_ROOT=$(git rev-parse --show-toplevel)

rm -rf $YAML_CPP
git clone https://github.com/jbeder/yaml-cpp $YAML_CPP && \
  mkdir $YAML_CPP/build && \
  cd $YAML_CPP/build && \
  CC=$(which gcc) CXX=$(which g++) \
    cmake -DCMAKE_INSTALL_PREFIX=$PROJECT_ROOT .. && \
  make && \
  make install && \
  rm -r $PROJECT_ROOT/include/gmock  $PROJECT_ROOT/include/gtest

