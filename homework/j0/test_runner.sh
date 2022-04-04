#!/bin/bash
rm test_runner.out

for f in $(find ../j0_test_cases/ -name "*.java" -type f)
do ./j0 -symtab $f >> test_runner.out
done
