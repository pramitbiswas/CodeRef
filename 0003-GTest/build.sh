#!/bin/sh

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )

rm -rf $SCRIPT_DIR/build
mkdir $SCRIPT_DIR/build
cd $SCRIPT_DIR/build
cmake -DCMAKE_BUILD_TYPE=Debug -S ../ -B .
# cmake -DCMAKE_BUILD_TYPE=Release -S ../ -B .
# cmake --build . --target clean
cmake --build .
# cd -
yes "" | head -n3
