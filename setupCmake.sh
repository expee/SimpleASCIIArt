#!/bin/bash

if  [ ! -d _build ]; then
	mkdir _build
fi

cd _build

if  [ ! -d unixMakefiles ]; then
	mkdir unixMakefiles
fi

cd unixMakefiles
echo ================================================================
echo ==                  CREATING UNIX MAKEFILES                   ==
echo ================================================================
cmake -G "Unix Makefiles" ../../
cd ..
