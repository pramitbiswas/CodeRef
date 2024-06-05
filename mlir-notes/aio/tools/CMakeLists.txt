get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)

set(LLVM_LINK_COMPONENTS
  Support
)

set(LIBS
  ${dialect_libs}
  # MLIRJoy
  MLIRParser
  MLIRSupport
  MLIRIR
  MLIROptLib
  MLIRPass
)

add_llvm_executable(flow-opt opt.cpp)
# add_mlir_tool(flow-opt
#   opt.cpp

#   DEPENDS
#   ${LIBS}
# )

# update compile flags in target properties
target_link_libraries(flow-opt PRIVATE ${LIBS})
llvm_update_compile_flags(flow-opt)


mlir_check_all_link_libraries(flow-opt)
