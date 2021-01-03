#!/bin/bash

cd build
rm -rf *
echo "All files deleted from build/"
cmake -DCMAKE_BUILD_TYPE=Debug ..
make