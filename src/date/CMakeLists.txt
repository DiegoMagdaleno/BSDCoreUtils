add_executable(date date.c)

target_link_libraries(date PRIVATE compat)
target_link_libraries(date PRIVATE util)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE -D_XOPEN_SOURCE")


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/date.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)