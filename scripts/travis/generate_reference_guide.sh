#!/bin/bash

set -ev

# setup git
git config --global user.email "gammasoft71@gmail.com"
git config --global user.name "gammasoft71"

# Clone switch-doc
if [ -d "build/ReferenceGuide" ]; then rm -r -f build/ReferenceGuide; fi
git clone https://github.com/gammasoft71/Switch-doc.git build/ReferenceGuide

# generate, build and install 3rdparty
cd build/3rdparty
cmake ../../3rdparty -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target install -- -j8
cd ../..

# Generating documentation
cd build
cmake .. -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=~/usr/local -DCMAKE_CXX_COMPILER=clang++-3.9
cmake --build . --target Switch.ReferenceGuide
cd ..

# check doxygen results and display error
#if [[ -s build/reference_guide/doxygen_warnings.txt ]]; then
#  echo "You must fix doxygen before submitting a pull request"
#  echo ""
#  cat build/reference_guide/doxygen_warnings.txt
#  exit -1
#fi

# Publishing documentation
cd build/ReferenceGuide
if [[ -e doxygen_warnings.txt ]]; then rm doxygen_warnings.txt; fi
git add --all
git commit -m "Generate Reference Guide [$TRAVIS_BUILD_NUMBER]"
git push "https://${GH_TOKEN}@github.com/gammasoft71/Switch-doc.git" master > /dev/null 2>&1 
cd ../..