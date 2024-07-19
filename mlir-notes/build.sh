#!/bin/bash

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )
cd ${SCRIPT_DIR}

source ./.env
pyenv activate mlir-notes-3.12.3
echo "ToDo: FIX virtualenv error"

rm -rf ${SCRIPT_DIR}/build
# cmake -B ${SCRIPT_DIR}/build -S ${SCRIPT_DIR} \
cmake -G Ninja -B ${SCRIPT_DIR}/build -S ${SCRIPT_DIR} \
  -DMLIR_DIR=$MLIR_DIR \
  -DLLVM_DIR=$LLVM_DIR
cmake --build build -j$((`nproc`+1))
cmake --build build -j$((`nproc`+1)) --target mlir-doc
cmake --build build -j$((`nproc`+1)) --target check-mlir-flow
# ${SCRIPT_DIR}/build/bin/flow-opt --help-list
# OVERVIEW: Read mlir file and display

# Available Dialects: builtin
# USAGE: flow-opt [options] <input file>

# OPTIONS:
#   --allow-unregistered-dialect                         - Allow operation with no registered dialects
#   --color                                              - Use colors in output (default=autodetect)
#   --dump-pass-pipeline                                 - Print the pipeline that will be run
#   --elide-resource-data-from-bytecode                  - Elide resources when generating bytecode
#   --emit-bytecode                                      - Emit bytecode when generating output
#   --emit-bytecode-version=<value>                      - Use specified bytecode when generating output
#   --help                                               - Display available options (--help-hidden for more)
#   --irdl-file=<filename>                               - IRDL file to register before processing the input
#   --load-dialect-plugin=<string>                       - Load dialects from plugin library
#   --load-pass-plugin=<string>                          - Load passes from plugin library
#   --log-actions-to=<string>                            - Log action execution to a file, or stderr if  '-' is passed
#   --log-mlir-actions-filter=<string>                   - Comma separated list of locations to filter actions from logging
#   --mlir-debug-counter=<string>                        - Comma separated list of debug counter skip and count arguments
#   --mlir-disable-threading                             - Disable multi-threading within MLIR, overrides any further call to MLIRContext::enableMultiThreading()
#   --mlir-elide-elementsattrs-if-larger=<uint>          - Elide ElementsAttrs with "..." that have more elements than the given upper limit
#   --mlir-elide-resource-strings-if-larger=<uint>       - Elide printing value of resources if string is too long in chars.
#   --mlir-enable-debugger-hook                          - Enable Debugger hook for debugging MLIR Actions
#   --mlir-generate-reproducer=<filename>                - Generate an mlir reproducer at the provided filename (no crash required)
#   --mlir-pass-pipeline-crash-reproducer=<string>       - Generate a .mlir reproducer file at the given output path if the pass manager crashes or fails
#   --mlir-pass-pipeline-local-reproducer                - When generating a crash reproducer, attempt to generated a reproducer with the smallest pipeline.
#   --mlir-pass-statistics                               - Display the statistics of each pass
#   --mlir-pass-statistics-display=<value>               - Display method for pass statistics
#     =list                                              -   display the results in a merged list sorted by pass name
#     =pipeline                                          -   display the results with a nested pipeline view
#   --mlir-pretty-debuginfo                              - Print pretty debug info in MLIR output
#   --mlir-print-debug-counter                           - Print out debug counter information after all counters have been accumulated
#   --mlir-print-debuginfo                               - Print debug info in MLIR output
#   --mlir-print-elementsattrs-with-hex-if-larger=<long> - Print DenseElementsAttrs with a hex string that have more elements than the given upper limit (use -1 to disable)
#   --mlir-print-ir-after=<pass-arg>                     - Print IR after specified passes
#   --mlir-print-ir-after-all                            - Print IR after each pass
#   --mlir-print-ir-after-change                         - When printing the IR after a pass, only print if the IR changed
#   --mlir-print-ir-after-failure                        - When printing the IR after a pass, only print if the pass failed
#   --mlir-print-ir-before=<pass-arg>                    - Print IR before specified passes
#   --mlir-print-ir-before-all                           - Print IR before each pass
#   --mlir-print-ir-module-scope                         - When printing IR for print-ir-[before|after]{-all} always print the top-level operation
#   --mlir-print-local-scope                             - Print with local scope and inline information (eliding aliases for attributes, types, and locations
#   --mlir-print-op-on-diagnostic                        - When a diagnostic is emitted on an operation, also print the operation as an attached note
#   --mlir-print-skip-regions                            - Skip regions when printing ops.
#   --mlir-print-stacktrace-on-diagnostic                - When a diagnostic is emitted, also print the stack trace as an attached note
#   --mlir-print-value-users                             - Print users of operation results and block arguments as a comment
#   --mlir-timing                                        - Display execution times
#   --mlir-timing-display=<value>                        - Display method for timing data
#     =list                                              -   display the results in a list sorted by total time
#     =tree                                              -   display the results ina with a nested tree view
#   --no-implicit-module                                 - Disable implicit addition of a top-level module op during parsing
#   -o <filename>                                        - Output filename
#   --pass-pipeline=<string>                             - Textual description of the pass pipeline to run
#   --profile-actions-to=<string>                        - Profile action execution to a file, or stderr if  '-' is passed
#   --run-reproducer                                     - Run the pipeline stored in the reproducer
#   --show-dialects                                      - Print the list of registered dialects and exit
#   --split-input-file                                   - Split the input file into pieces and process each chunk independently
#   --verify-diagnostics                                 - Check that emitted diagnostics match expected-* lines on the corresponding line
#   --verify-each                                        - Run the verifier after each transformation pass
#   --verify-roundtrip                                   - Round-trip the IR after parsing and ensure it succeeds
#   --version                                            - Display the version of this program
