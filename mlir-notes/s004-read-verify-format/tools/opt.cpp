#include "mlir/IR/OwningOpRef.h"
#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"


int main(int argc, char **argv)
{
  mlir::DialectRegistry registry;

  // Register and parse command line options.
  std::string inputFilename, outputFilename;
  std::tie(inputFilename, outputFilename) =
      registerAndParseCLIOptions(argc, argv, "Read mlir file and display\n", registry);

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

  llvm::SourceMgr sourceMgr;
  sourceMgr.AddNewSourceBuffer(std::move(file), llvm::SMLoc());

  mlir::OwningOpRef<mlir::Operation *> op = mlir::parseSourceFile(sourceMgr, &context);
  if (!op)
  {
    llvm::errs() << "\nFailed to parse input file\n";
    exit(1);
  }
  output->os() << *(op.get()) << "\n";

  // mlir::MlirOptMainConfig config = mlir::MlirOptMainConfig::createFromCLOptions();
  // MlirOptMain(output->os(), std::move(file), registry, config);

  return 0;
}
