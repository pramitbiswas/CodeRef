#!/bin/bash

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )
cd ${SCRIPT_DIR}

source ./.env

rm -rf ${SCRIPT_DIR}/build

cmake -G Ninja -B ${SCRIPT_DIR}/build -S ${SCRIPT_DIR} \
  -DMLIR_DIR=$MLIR_DIR \
  -DLLVM_DIR=$LLVM_DIR
cmake --build build
