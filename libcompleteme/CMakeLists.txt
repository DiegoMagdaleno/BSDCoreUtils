list(APPEND youcompleteme
    src/linked_strings.c)

add_library(youcompleteme
    ${youcompleteme})


add_executable(aaaaa src/linked_strings.c src/first_component.c src/test.c)

target_include_directories(youcompleteme PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")