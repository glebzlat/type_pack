cmake_minimum_required(VERSION 3.0.0)

project(type_pack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(type_pack INTERFACE)
target_compile_options(type_pack INTERFACE
    -Wall -Wpedantic -Wextra )
target_include_directories(type_pack INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(TYPE_PACK_TESTING)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)
endif()

if(TYPE_PACK_DOC)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/doc)
endif()
