set(LIBS
  MLIRParser
  MLIROptLib
)

add_llvm_executable(flow-opt opt.cpp)

# update compile flags in target properties
llvm_update_compile_flags(flow-opt)

target_link_libraries(flow-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(flow-opt)
