cmake_minimum_required(VERSION 3.10)
project(register-parser)

set(CMAKE_CXX_STANDARD 17)

# Add include directory
include_directories(include)

# Add all source files
file(GLOB SOURCES
    src/*.cpp
)

# Create executable
add_executable(regspec ${SOURCES})