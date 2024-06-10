get_filename_component(JOY_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/Dialect/Joy/ ABSOLUTE)

add_mlir_dialect_library(MLIRJoy
	JoyDialect.cpp
	JoyOps.cpp

		ADDITIONAL_HEADER_DIRS
		${JOY_INC_DIR}

		DEPENDS
		MLIRJoyOpsIncGen

LINK_LIBS PUBLIC
MLIRIR
)
