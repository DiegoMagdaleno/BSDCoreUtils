add_executable(ls ls.c main.c utf8.c util.c print.c cmp.c)

target_link_libraries(ls PRIVATE compat)
target_link_libraries(ls PRIVATE ncurses)
target_link_libraries(ls PRIVATE util)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/ls.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/ls.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)