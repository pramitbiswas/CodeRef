#include "mlir/IR/Builders.h"
#include "mlir/IR/OpImplementation.h"

#include "Dialect/Joy/JoyDialect.h"
#include "Dialect/Joy/JoyOps.h"

#include "Dialect/Joy/JoyOpsDialect.cpp.inc"

using namespace mlir;
using namespace joy;

void JoyDialect::initialize() {
  // allowUnknownOperations(true);
  // allowUnknownTypes(true);

  addOperations<
#define GET_OP_LIST
#include "Dialect/Joy/JoyOps.cpp.inc"
      >();
}
