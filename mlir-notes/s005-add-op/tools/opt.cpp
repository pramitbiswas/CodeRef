#include "mlir/IR/OwningOpRef.h"
#include "mlir/Parser/Parser.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Tools/mlir-opt/MlirOptMain.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"

#include "Dialect/Joy/JoyDialect.h"
#include "Dialect/Joy/JoyOps.h"

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

  registry.insert<joy::JoyDialect>();
  // context.allowUnregisteredDialects(true);
  // context.getOrLoadDialect<joy::JoyDialect>();
  // context.appendDialectRegistry(registry);

  // llvm::SourceMgr sourceMgr;
  // sourceMgr.AddNewSourceBuffer(std::move(file), llvm::SMLoc());

  // mlir::OwningOpRef<mlir::Operation *> op = mlir::parseSourceFile(sourceMgr, &context);
  // if (!op)
  // {
  //   llvm::errs() << "\nFailed to parse input file\n";
  //   exit(1);
  // }
  // output->os() << *(op.get()) << "\n";

  // // Print the loaded dialects
  // llvm::outs() << "Loaded dialects:\n";
  // for (const auto &dialect : context.getLoadedDialects())
  // {
  //   llvm::outs() << dialect->getNamespace().str() << "\n";
  // }
  // llvm::outs().flush();

  auto config = mlir::MlirOptMainConfig::createFromCLOptions();
  config.showDialects(true);
  return mlir::asMainReturnCode(mlir::MlirOptMain(output->os(),
                                                  std::move(file),
                                                  registry,
                                                  config));
}
