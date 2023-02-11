project(type_pack_doc)

find_package(Doxygen REQUIRED)

set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

find_program(CLANG clang)

if(CLANG)
    set(DOC_CLANG_ASSISTED_PARSING YES)
    set(DOC_CLANG_DATABASE_PATH ${CMAKE_BINARY_DIR})
else()
    set(CLANG_ASSISTED_PARSING NO)
endif()

configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

add_custom_target( doc_doxygen ALL
    COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    VERBATIM
    USES_TERMINAL
)
