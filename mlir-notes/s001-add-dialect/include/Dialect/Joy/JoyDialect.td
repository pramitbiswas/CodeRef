#ifndef HELLO_DIALECT
#define HELLO_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// Joy dialect definition.
//===----------------------------------------------------------------------===//

def Joy_Dialect : Dialect {
    let name = "joy";
    let summary = "A joy out-of-tree MLIR dialect.";
    let description = [{
        This dialect is minimal example to implement joy-world kind of sample code
        for MLIR.
    }];
    let cppNamespace = "::joy";
    let hasConstantMaterializer = 1;
}

//===----------------------------------------------------------------------===//
// Base joy operation definition.
//===----------------------------------------------------------------------===//

class Joy_Op<string mnemonic, list<Trait> traits = []> :
        Op<Joy_Dialect, mnemonic, traits>;

#endif // HELLO_DIALECT
