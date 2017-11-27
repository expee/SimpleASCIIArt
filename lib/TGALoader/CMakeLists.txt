file(GLOB src "src/*cpp")

add_library(TGALoader SHARED ${src})
target_include_directories(TGALoader PUBLIC ./include)
