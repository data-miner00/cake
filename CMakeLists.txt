cmake_minimum_required(VERSION 3.10)

project(Cake VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADER_FILES include/lib.h)

configure_file(include/original.h.in include/original.h)

add_executable(
  ${PROJECT_NAME}
  src/main.cxx
)

target_include_directories(Cake PUBLIC "${PROJECT_BINARY_DIR}/include")
