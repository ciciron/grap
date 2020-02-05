
cmake_minimum_required (VERSION 3.0)

project (grap)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pthread -std=c++14")

file (GLOB source_files "src/*.cpp")

find_package(X11 REQUIRED)

link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

add_executable (grap ${source_files})

set_target_properties(grap PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_include_directories(grap PRIVATE "${PROJECT_SOURCE_DIR}/include/")