cmake_minimum_required(VERSION 3.10)
project(vector)

# Add C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Source files
file(GLOB SOURCES "src/*.cpp")

# Executable
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin) # Define the output directory
add_executable(${PROJECT_NAME} ${SOURCES})

# Testing (Optional)
enable_testing()