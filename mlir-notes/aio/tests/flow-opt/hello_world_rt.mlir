// RUN: flow-opt -allow-unregistered-dialect --verify-roundtrip %s | FileCheck %s

// CHECK: "hello.world"
"hello.world"() : () -> ()
