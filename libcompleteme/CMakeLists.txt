list(APPEND youcompleteme
    src/linked_strings.c
    src/first_component.c
    src/is_prefixed_with.c
    src/dev_opera.c
    src/starts_with.c
    src/timeoperations.c
    src/convert.c)

add_library(youcompleteme
    ${youcompleteme})


target_link_libraries(youcompleteme PUBLIC compat)

target_include_directories(youcompleteme PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")