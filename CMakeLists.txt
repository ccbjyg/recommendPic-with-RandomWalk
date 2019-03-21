cmake_minimum_required(VERSION 3.13)

#编译器
SET (CMAKE_C_COMPILER             "clang")
SET (CMAKE_C_FLAGS                "-Wall -std=c99 --target=x86_64-w64-mingw")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER             "clang++")
SET (CMAKE_CXX_FLAGS                "-Wall --target=x86_64-w64-mingw")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

#项目声明
project(recommend)

# 添加头文件路径和资源路径
include_directories(include)
aux_source_directory(. DIR_SRCS)

add_subdirectory(src)

add_library(recommend SHARED librecommend.cpp)
# add_executable(recommend ${DIR_SRCS})

target_link_libraries(recommend src)

# 本环境下, 指令如下
# cmake -G "MinGW Makefiles" (source);
# mingw32-make.exe||make(renamed)