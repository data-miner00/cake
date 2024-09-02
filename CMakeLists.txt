# Declare minimum version
cmake_minimum_required(VERSION 3.10)

# Define what this project is about
project(
  # The project name will be available under `PROJECT_NAME` variable
  Cake

  VERSION 1.0.0.0
  DESCRIPTION "Playing with CMake"
  LANGUAGES CXX
)

set(AUTHOR_NAME shaun)

# Enabling C++11 features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# For clangd to pick up
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

# File replacement
configure_file(
  # Input from the root directory
  include/original.h.in

  # Output in the build directory
  include/original.h
)

# Finds the external fmt library (https://fmt.dev)
# pacman -S fmt
find_package(fmt)

# Adds a subdirectory to be included in the build
# The output will also be named `library` but in the build folder.
set(LIBRARY_NAME "library")
add_subdirectory(${LIBRARY_NAME})

# Declares the executable
add_executable(
  # Name of executable. Using project name.
  ${PROJECT_NAME}

  # Source of executable
  src/main.cxx
)

target_link_libraries(
  ${PROJECT_NAME} PUBLIC
  ${LIBRARY_NAME}
  fmt::fmt
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  "${PROJECT_BINARY_DIR}/include"
  "${PROJECT_SOURCE_DIR}/library"
)

# First boolean variable indicates that the recently called
# `project()` was in the top level `CMakeLists.txt` file.
if (PROJECT_IS_TOP_LEVEL AND UNIX)
  # Create symlink to compile_commands.json
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
endif()

