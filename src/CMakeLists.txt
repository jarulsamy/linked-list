
# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/include/modern/*.hpp")
set(HEADER_LIST "${PROJECT_SOURCE_DIR}/include/list.hpp")
SET(TARGET_NAME "LinkedList.o")

# find_package(PACKAGE_NAME REQUIRED)
# include_directories(${SOME_INCLUDE_DIR})

# Add all the src cpp files with the headers
add_executable(${TARGET_NAME} main.cpp ${HEADER_LIST})

target_link_libraries(${TARGET_NAME})

# Ensure everything in `include` is included.
target_include_directories(${TARGET_NAME} PUBLIC ../include)

# C++11
target_compile_features(${TARGET_NAME} PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
source_group(TREE "${PROJECT_SOURCE_DIR}/include" PREFIX "Header Files" FILES ${HEADER_LIST})
