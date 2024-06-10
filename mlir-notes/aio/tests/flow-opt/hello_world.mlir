// RUN: flow-opt -allow-unregistered-dialect %s | FileCheck %s

// CHECK: "hello.world"
"hello.world"() : () -> ()
