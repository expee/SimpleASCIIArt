file(GLOB src "src/*cpp")

add_library(SimpleAsciiArt SHARED ${src})
target_include_directories(SimpleAsciiArt PUBLIC ./include)
