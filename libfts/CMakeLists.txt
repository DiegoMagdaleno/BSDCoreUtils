list(APPEND fts
    src/fts.c)

add_library(fts STATIC ${fts})

target_include_directories(fts PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")