cmake_minimum_required(VERSION 3.0)

project(AsciiArt_Generator)

include_directories(./include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	set(warnings "-Wall")
	set(optim "-O2")
	set(codeStd "-std=c++11")
	add_definitions(-D__STDC_LIB_EXT1__)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	set(warnings "/W4")
	set(optim "/O2")
	set(codeStd "")
	add_definitions(/D_MSVC)
endif()

set(CMAKE_CXX_FLAGS "${codeStd} ${warnings} ${optim}")

add_subdirectory(lib/SimpleAsciiArt)
add_subdirectory(lib/TGALoader)

file(GLOB src "src/*cpp")
add_executable(AsciiArt ${src})

target_link_libraries(AsciiArt PRIVATE SimpleAsciiArt PRIVATE TGALoader)
