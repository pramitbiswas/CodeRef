#ifndef JOY_OPS
#define JOY_OPS

include "JoyDialect.td"
// include "mlir/Interfaces/SideEffectInterfaces.td"

def HelloOp : Joy_Op<"hello"> {
    let summary = "Joy: Hello World";
    let description = [{
        The dummy operation, and produces no results.
    }];

    // https://mlir.llvm.org/docs/DefiningDialects/Operations/#declarative-assembly-format
    // The format specification has a certain set of requirements that must be adhered to:
    // 1. The output and operation name are never shown as they are fixed and cannot be altered.
    // 2. All operands within the operation must appear within the format, either individually or with the operands directive.
    // 3. All regions within the operation must appear within the format, either individually or with the regions directive.
    // 4. All successors within the operation must appear within the format, either individually or with the successors directive.
    // 5. All operand and result types must appear within the format using the various type directives, either individually or with the operands or results directives.
    // 6. The attr-dict directive must always be present.
    // 7. Must not contain overlapping information; e.g. multiple instances of ‘attr-dict’, types, operands, etc.
    // 8. Note that attr-dict does not overlap with individual attributes. These attributes will simply be elided when printing the attribute dictionary.
    let assemblyFormat = [{
        `{` `beautiful` ` ` `people` `}` attr-dict `(``)` `:` `(``)` `->` `(``)`
    }];
}

#endif // JOY_OPS
