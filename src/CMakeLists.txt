
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST "${cpp-template_SOURCE_DIR}/include/some_header.h")

# find_package(PACKAGE_NAME REQUIRED)
# include_directories(${SOME_INCLUDE_DIR})

# Add all the src cpp files with the headers
add_executable(EXE_NAME main.cpp ${HEADER_LIST})
# gcc -lPACKAGE_NAME
target_link_libraries(EXE_NAME PACKAGE_NAME)

# Ensure everything in `include` is included.
target_include_directories(EXE_NAME PUBLIC ../include)

# C++11
target_compile_features(EXE_NAME PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
