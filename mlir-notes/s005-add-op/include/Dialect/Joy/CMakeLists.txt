# Add the JoyOps for the dialect operaions
add_mlir_dialect(JoyOps joy)

# Generate documentation of joy Dialect and its Ops
# doc_filename output_file output_directory command
add_mlir_doc(JoyDialect JoyDialect Joy/ -gen-dialect-doc)
add_mlir_doc(JoyOps JoyOps Joy/ -gen-op-doc)
