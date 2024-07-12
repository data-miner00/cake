cmake_minimum_required(VERSION 3.10)

project(Cake VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(HEADER_FILES include/lib.h)
set(CMAKE_EXPORT_COMPILE_COMMANDS True)

configure_file(include/original.h.in include/original.h)

add_executable(
  ${PROJECT_NAME}
  src/main.cxx
)

target_include_directories(Cake PUBLIC "${PROJECT_BINARY_DIR}/include")

if (PROJECT_IS_TOP_LEVEL AND UNIX)
  # Create symlink to compile_commands.json
  execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
      ${CMAKE_BINARY_DIR}/compile_commands.json
      ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
endif()

