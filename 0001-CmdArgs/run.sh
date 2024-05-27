#!/bin/sh

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )

mkdir -p $SCRIPT_DIR/build
cd $SCRIPT_DIR/build
cmake -S ../ -B .
cmake --build . --target clean
cmake --build .
# cd -
yes "" | head -n3
./cmdargs "$@"
