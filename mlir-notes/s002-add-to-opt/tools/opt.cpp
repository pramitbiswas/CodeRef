#include "mlir/IR/AsmState.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"

#include "Dialect/Joy/JoyDialect.h"

int main(int argc, char **argv)
{
  // Register any command line options.
  mlir::registerMLIRContextCLOptions();
  mlir::registerAsmPrinterCLOptions();

  // Parse them
  // cl::ParseCommandLineOptions(argc, argv, "PM compiler\n");

  // Get mlir context
  mlir::MLIRContext context;

  // load required dialects in the mlir context
  context.getOrLoadDialect<joy::JoyDialect>();
  context.getOrLoadDialect<mlir::func::FuncDialect>();

  return 0;
}
