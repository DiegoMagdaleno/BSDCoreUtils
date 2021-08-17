list(APPEND youcompleteme
    src/linked_strings.c
    src/first_component.c)

add_library(youcompleteme
    ${youcompleteme})


target_include_directories(youcompleteme PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")