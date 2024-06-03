get_filename_component(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../include/ ABSOLUTE)

add_mlir_dialect_library(MLIRJoy
	JoyDialect.cpp
	JoyOps.cpp

		ADDITIONAL_HEADER_DIRS
		${INC_DIR}

		DEPENDS
		MLIRJoyOpsIncGen

LINK_LIBS PUBLIC
MLIRIR
)
