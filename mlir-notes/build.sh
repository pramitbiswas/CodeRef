#!/bin/bash

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )
cd ${SCRIPT_DIR}

source ./.env
pyenv activate mlir-notes-3.12.3
echo "ToDo: FIX virtualenv error"

rm -rf ${SCRIPT_DIR}/build
# cmake -B ${SCRIPT_DIR}/build -S ${SCRIPT_DIR} \
cmake -G Ninja -B ${SCRIPT_DIR}/build -S ${SCRIPT_DIR} \
  -DMLIR_DIR=$MLIR_DIR \
  -DLLVM_DIR=$LLVM_DIR
cmake --build build -j$((`nproc`+1))
cmake --build build -j$((`nproc`+1)) --target check-mlir-flow
