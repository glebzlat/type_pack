cmake_minimum_required(VERSION 3.0.0)

project(type_pack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(tptest main.cpp)
target_compile_options(tptest PRIVATE
    -Wall -Wpedantic -Wextra )
target_include_directories(tptest PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

include(CTest)
add_test(NAME TP_Test COMMAND tptest)

add_custom_target(MakeTest ALL
    ctest --output-on-failure --test-timeout 10
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
    VERBATIM
    DEPENDS tptest
)
