#include "mlir/Tools/mlir-opt/MlirOptMain.h"
// #include "mlir/IR/AsmState.h"
#include "mlir/InitAllDialects.h"
// #include "mlir/IR/MLIRContext.h"
#include "mlir/Support/FileUtilities.h"
#include "llvm/Support/SourceMgr.h"
// #include "mlir/IR/DialectRegistry.h"
#include "mlir/IR/OwningOpRef.h"
// #include "mlir/IR/Operation.h"
#include "mlir/Parser/Parser.h"
#include "llvm/Support/ToolOutputFile.h"

// #include "llvm/Support/CommandLine.h"

// #include "mlir/Support/LLVM.h"

// #include "Dialect/Joy/JoyDialect.h"

#include <iostream>

// static llvm::cl::opt<std::string> inputFilename(llvm::cl::Positional,
//                                                 llvm::cl::desc("<input file>"),
//                                                 llvm::cl::init("-"),
//                                                 llvm::cl::value_desc("filename"));

int main(int argc, char **argv)
{

  // Register any command line options.
  // mlir::registerMLIRContextCLOptions();
  // mlir::registerAsmPrinterCLOptions();

  // Parse them
  // llvm::cl::ParseCommandLineOptions(argc, argv, "PM compiler\n");
  /*
  // Get mlir context
  mlir::MLIRContext context;

  // load required dialects in the mlir context
  context.getOrLoadDialect<joy::JoyDialect>();
  context.getOrLoadDialect<mlir::func::FuncDialect>();
  */
  //===-------------------------------------------------------------------------
  /*
  mlir::DialectRegistry registry;
  mlir::MLIRContext context(registry, mlir::MLIRContext::Threading::DISABLED);
  context.allowUnregisteredDialects(true);
  mlir::OwningOpRef<mlir::Operation *> op = mlir::parseSourceFile(sourceMgr, &context);
  if (!op)
  {
    llvm::errs() << "\nFailed to parse input file\n";
    exit(1);
  }
  output->os() << *(op.get()) << "\n";

  return 0;
  */
  //===-------------------------------------------------------------------------
  mlir::DialectRegistry registry;

  // Register and parse command line options.
  std::string inputFilename, outputFilename;
  std::tie(inputFilename, outputFilename) =
      registerAndParseCLIOptions(argc, argv, "Read mlir file and display\n", registry);

  std::cout << inputFilename << std::endl;
  std::cout << outputFilename << std::endl;

  std::string errorMessage;
  auto file = mlir::openInputFile(inputFilename, &errorMessage);
  if (!file)
  {
    llvm::errs() << errorMessage << "\n";
    exit(1);
  }
  auto output = mlir::openOutputFile(outputFilename, &errorMessage);
  if (!output)
  {
    llvm::errs() << errorMessage << "\n";
    exit(1);
  }

  mlir::MLIRContext context(registry, mlir::MLIRContext::Threading::DISABLED);
  context.allowUnregisteredDialects(true);
  context.getOrLoadDialect<mlir::func::FuncDialect>();

  // llvm::SourceMgr sourceMgr;
  // sourceMgr.AddNewSourceBuffer(std::move(file), llvm::SMLoc());

  // mlir::OwningOpRef<mlir::Operation *> op = mlir::parseSourceFile(sourceMgr, &context);
  // if (!op)
  // {
  //   llvm::errs() << "\nFailed to parse input file\n";
  //   exit(1);
  // }
  // output->os() << *(op.get()) << "\n";

  mlir::MlirOptMainConfig config = mlir::MlirOptMainConfig::createFromCLOptions();
  MlirOptMain(output->os(), std::move(file), registry, config);

  return 0;
}
