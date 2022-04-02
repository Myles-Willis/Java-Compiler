#!/bin/bash

for f in $(find ../j0_test_cases/ -name "*.java" -type f)
do ./j0 $f
done
