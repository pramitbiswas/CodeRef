#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"

#include "Dialect/Joy/JoyDialect.h"
#include "Dialect/Joy/JoyOps.h"

using namespace mlir;
using namespace joy;

void JoyDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Dialect/Joy/JoyOps.cpp.inc"
      >();
}
