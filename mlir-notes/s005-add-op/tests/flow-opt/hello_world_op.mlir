// RUN: flow-opt -mlir-print-debuginfo %s | FileCheck %s
// COM: flow-opt -allow-unregistered-dialect -mlir-print-debuginfo %s | FileCheck %s

// COM: "joy.hello"() : () -> () loc("{{.*}}":{{[0-9]*}}:{{[0-9]*}})
// COM: "joy.hello"() : () -> () loc(#loc{{[0-9]*}})
// CHECK: joy.hello{beautiful people}() : () -> () loc(#loc{{[0-9]*}})
"joy.hello"() : () -> ()
