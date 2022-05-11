#!/bin/bash

mkdir -p build
pushd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DGTEST_DIR=../../vendor/fused_gmock -DGCOV=ON -LH
popd
