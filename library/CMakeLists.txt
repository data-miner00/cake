option(USE_LIB2 "Use library 2 instead" ON)

add_library(library lib1.cxx lib2.cxx)

if (USE_LIB2)
  target_compile_definitions(library PRIVATE "USE_LIB2")
endif()

