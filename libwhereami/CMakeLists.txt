list(APPEND whereami
    src/whereami.c)

add_library(whereami STATIC
    ${whereami})

target_include_directories(whereami PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")