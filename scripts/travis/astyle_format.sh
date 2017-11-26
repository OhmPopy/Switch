#!/bin/bash

set -ev

# format code with AStyle
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DDOWNLOAD_ASTYLE=ON -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target Switch.Format
cd ..

# check file changed and display error
if [[ -n $(git diff) ]]; then
  echo "You must run make format before submitting a pull request"
  echo ""
  git diff
  exit -1
fi
