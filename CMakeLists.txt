cmake_minimum_required(VERSION 3.5.0)
project(world_simulator VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB SOURCES "*.cpp" "*.h")
add_executable(world_simulator ${SOURCES})

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
