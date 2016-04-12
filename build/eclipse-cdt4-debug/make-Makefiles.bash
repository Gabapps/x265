#!/bin/bash
# Run this from within a bash shell
cmake -G "Eclipse CDT4 - Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug ../../source && ccmake ../../source
