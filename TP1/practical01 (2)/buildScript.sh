#!/bin/bash

cd sfmlGraphicsPipeline

cd extlib
make -j6
cd ..

rm -rf build
mkdir build
cd build
cmake ..
make -j6
cd ../..

cd sampleProject

rm -rf build
mkdir build
cd build
cmake ..
make -j6

./main&
