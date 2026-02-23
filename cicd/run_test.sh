#!/bin/bash
set -e

echo "Tests"
make all || { make clean; exit 1; }
make test || { make clean; exit 1; }
./test_3.sh || { exit 1; }
