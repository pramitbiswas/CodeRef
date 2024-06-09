#!/bin/sh

SCRIPT_DIR=$( cd -- "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P )

sh $SCRIPT_DIR/build.sh

${SCRIPT_DIR}/build/str
