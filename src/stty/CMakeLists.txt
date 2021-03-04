add_executable(stty cchar.c gfmt.c key.c modes.c print.c stty.c)

target_link_libraries(stty PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stty.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/stty.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
