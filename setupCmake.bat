@echo off

if not exist "_build" (
	mkdir _build
)

cd _build

if not exist "vs2017" (
	mkdir vs2017
)

pushd vs2017
echo ================================================================
echo ==              CREATING VS 2017 SOLUTION FILES               ==
echo ================================================================
cmake -G "Visual Studio 15 2017" ../../
popd

if not exist "minGW" (
	mkdir minGW
)

pushd minGW
echo ================================================================
echo ==                  CREATING MINGW MAKEFILES                  ==
echo ================================================================
cmake -G "MinGW Makefiles" ../../
popd