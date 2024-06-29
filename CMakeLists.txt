cmake_minimum_required (VERSION 3.7)

set (TARGET volk-test)

project (${TARGET})

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

set (EXECUTABLE_OUTPUT_PATH "../bin")

file (GLOB INCLUDES "./include/*.h")
file (GLOB CPP_SOURCES "./src/*.cpp")
file (GLOB C_SOURCES "./src/*.c")

add_executable (${TARGET} ${CPP_SOURCES} ${C_SOURCES} ${INCLUDES})

target_include_directories (${TARGET} PRIVATE ./include/)
target_include_directories (${TARGET} PRIVATE $ENV{VK_HEADERS})
