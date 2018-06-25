#!/bin/bash
#
# install-boost.sh
#
# Copyright (c) 2018 Ben Lindsay <benjlindsay@gmail.com>

PROJ_ROOT=$(pwd)
BOOST_VERSION=boost_1_67_0
TARBALL=$BOOST_VERSION.tar.bz2

if [ ! -f /tmp/$TARBALL ]; then
  wget -O /tmp/$TARBALL https://dl.bintray.com/boostorg/release/1.67.0/source/boost_1_67_0.tar.bz2
fi

rm -rf /tmp/$BOOST_VERSION
cd /tmp
tar -xjf $TARBALL
cd $BOOST_VERSION
./bootstrap.sh --prefix=$PROJ_ROOT --with-libraries=filesystem
b2_output=$(./b2 install)
echo $b2_output | head -50
echo "...\nSkipping a ton of lines of './b2 install' output"
echo $b2_output | tail -50
