#include "mlir/IR/AsmState.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"

#include "llvm/Support/CommandLine.h"

#include "Dialect/Joy/JoyDialect.h"

static llvm::cl::opt<std::string> inputFilename(llvm::cl::Positional,
                                                llvm::cl::desc("<input file>"),
                                                llvm::cl::init("-"),
                                                llvm::cl::value_desc("filename"));

int main(int argc, char **argv)
{
  // Register any command line options.
  mlir::registerMLIRContextCLOptions();
  mlir::registerAsmPrinterCLOptions();

  // Parse them
  llvm::cl::ParseCommandLineOptions(argc, argv, "PM compiler\n");

  // Get mlir context
  mlir::MLIRContext context;

  // load required dialects in the mlir context
  context.getOrLoadDialect<joy::JoyDialect>();
  context.getOrLoadDialect<mlir::func::FuncDialect>();

  return 0;
}
