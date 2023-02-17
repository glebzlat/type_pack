project(type_pack_test LANGUAGES CXX)

include(CTest)

# list of all test targets as a dependency for a test launcher target
set(EXEC_LIST)

macro(add_test_exec TEST_NAME DEPLIB)
    add_executable(${TEST_NAME} EXCLUDE_FROM_ALL ${ARGN})
    target_link_libraries(${TEST_NAME} PRIVATE ${DEPLIB})
    list(APPEND EXEC_LIST ${TEST_NAME})
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endmacro()

add_test_exec(Test1 type_pack test1.cpp)
add_test_exec(Concatenation type_pack test2.cpp)
add_test_exec(PushPop type_pack test3.cpp)
add_test_exec(ContainsFind type_pack test4.cpp)
add_test_exec(FindIf_PartialCaller type_pack test5.cpp)
add_test_exec(AnyAllNone type_pack test6.cpp)
add_test_exec(At_Generate type_pack test7.cpp)
add_test_exec(Count type_pack test8.cpp)
add_test_exec(Remove type_pack test9.cpp)
add_test_exec(Unique type_pack test10.cpp)
add_test_exec(Replace type_pack test11.cpp)
add_test_exec(Sub type_pack test12.cpp)
add_test_exec(LexicographicalCompare type_pack test13.cpp)
add_test_exec(MinMax type_pack test14.cpp)
add_test_exec(Sort type_pack test15.cpp)
add_test_exec(IsSorted type_pack test16.cpp)
add_test_exec(InheritanceLess type_pack test17.cpp)

add_custom_target(MakeTest ALL
    ctest --output-on-failure --test-timeout 10
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    USES_TERMINAL
    VERBATIM
    DEPENDS ${EXEC_LIST}
)
