# Declare a flag USE_LIB2
option(USE_LIB2 "Use library 2 instead" ON)

add_library(
  ${LIBRARY_NAME} STATIC

  lib1.cxx
  lib2.cxx
  bubble_sort.cxx
)

if (USE_LIB2)
  target_compile_definitions(${LIBRARY_NAME} PRIVATE "USE_LIB2")
endif()

