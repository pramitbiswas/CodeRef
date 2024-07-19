#!/bin/sh

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )

# rm -rf $SCRIPT_DIR/build

cmake -DCMAKE_BUILD_TYPE=Debug -S ${SCRIPT_DIR} -B ${SCRIPT_DIR}/build
# cmake -DCMAKE_BUILD_TYPE=Release -S ../ -B .
# cmake --build . --target clean
cmake --build ${SCRIPT_DIR}/build
# cd -
yes "" | head -n3
