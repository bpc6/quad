cmake_minimum_required(VERSION 3.27)
set(BUILD_SHARED_LIBS ON)
project(quad)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the path to JSBSim library and header files
set(JSBSIM_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/third_party/jsbsim/src")
set(JSBSIM_LIBRARY_DIR "${CMAKE_SOURCE_DIR}/third_party/jsbsim/build/src")

add_executable(quad main.cpp)

# Include JSBSim headers
target_include_directories(quad PRIVATE ${JSBSIM_INCLUDE_DIR})

# Link JSBSim library
target_link_libraries(quad PRIVATE ${JSBSIM_LIBRARY_DIR}/libJSBSim.a)
