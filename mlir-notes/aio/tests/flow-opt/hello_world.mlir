// RUN: flow-opt -allow-unregistered-dialect %s | FileCheck %s

func.func @main() {
    // CHECK: "hello.world"
    "hello.world"() : () -> ()
    return
}
