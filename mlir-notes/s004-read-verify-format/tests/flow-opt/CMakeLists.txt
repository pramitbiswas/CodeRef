set (FLOW_OPT_TEST_DEPENDS
      FileCheck count not
      flow-opt
    )

  add_lit_testsuite(check-mlir-flow "Running the MLIR for flow-opt tests"
    ${CMAKE_CURRENT_BINARY_DIR}
    DEPENDS
      ${FLOW_OPT_TEST_DEPENDS}
)
