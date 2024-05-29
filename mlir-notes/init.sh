#!/bin/bash

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )

CMAKE_V=3.29.3
LLVM_V=18.1.6

sudo DEBIAN_FRONTEND=noninteractive apt update
arr=(
  git
  python3
  python3-pip
  ninja-build
  ccache
  curl
  wget
  binutils
  libssl-dev
)

for i in "${arr[@]}"
do
  if ! [ -x "$(command -v ${i})" ];
  then
    sudo DEBIAN_FRONTEND=noninteractive apt install -y ${i}
  else
    echo "${i} is pre-installed"
  fi
done

if ! [ -x "$(command -v cmake)" ];
then
  cd ${SCRIPT_DIR}
  wget https://github.com/Kitware/CMake/releases/download/v${CMAKE_V}/cmake-${CMAKE_V}.tar.gz
  tar -xvf cmake-${CMAKE_V}.tar.gz
  cd cmake-${CMAKE_V}
  ./bootstrap --parallel=`nproc`
  make -j$((`nproc`+1))
  sudo make install
  cd ../
  rm -rf cmake-${CMAKE_V}*
else
  echo "cmake installed"
fi

if [ -d "${SCRIPT_DIR}/llvm-project/build/" ]; then
  echo "${SCRIPT_DIR}/llvm-project/build/ does exist."
else
  git submodule update --init --recursive

  cd ${SCRIPT_DIR}/llvm-project

  git config --global --add safe.directory ${SCRIPT_DIR}/mlir-notes/llvm-project
  git config --global --add safe.directory ${SCRIPT_DIR}/mlir-notes

  git checkout tags/llvmorg-${LLVM_V}
fi

cmake -G Ninja -S ${SCRIPT_DIR}/llvm-project/llvm -B ${SCRIPT_DIR}/llvm-project/build/ \
   -DLLVM_ENABLE_PROJECTS="mlir;bolt;clang;lld;clang-tools-extra;llvm" \
   -DLLVM_BUILD_EXAMPLES=ON \
   -DLLVM_TARGETS_TO_BUILD="Native;NVPTX;AMDGPU" \
   -DCMAKE_BUILD_TYPE=Release \
   -DLLVM_ENABLE_ASSERTIONS=ON \
   -DLLVM_CCACHE_BUILD=ON
cmake --build ${SCRIPT_DIR}/llvm-project/build/ -j$((`nproc`+1))
cmake --build ${SCRIPT_DIR}/llvm-project/build/ -j$((`nproc`+1)) --target check-mlir
