#!/bin/bash

EXCLUDE="build"
FILES="$( find $@ -path $@/$EXCLUDE -prune -o \
          -name *\.cc  -o                    \
          -name *\.cpp -o                    \
          -name *\.h   -o                    \
          -name *\.hpp )"
for i in $FILES
do
    if [[ $i != "$@/$EXCLUDE" ]] ; then
        echo $i
        clang-format -i $i
    fi
done
