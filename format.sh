#!/bin/bash

FILES="$( find .          \
          -name *\.cc  -o \
          -name *\.cpp -o \
          -name *\.h   -o \
          -name *\.hpp )"
for i in $FILES
do
    echo $i
    clang-format -i $i
done
