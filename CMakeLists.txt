cmake_minimum_required(VERSION 3.3.0)

project(leetcode)

set(CMAKE_BUILD_TYPE "Debug")

set(inc_dir "${PROJECT_SOURCE_DIR}/inc/")
set(src_dir "${PROJECT_SOURCE_DIR}/src/")

file(GLOB HEADERS_LIB "${inc_dir}/*.h" "${src_dir}/*.cpp")

add_executable(main main.cpp ${HEADERS_LIB})