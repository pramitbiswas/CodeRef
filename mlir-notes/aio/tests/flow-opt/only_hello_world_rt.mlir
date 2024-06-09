// RUN: flow-opt --verify-roundtrip %s | FileCheck %s

// CHECK: "hello.world"
"hello.world"() : () -> ()
