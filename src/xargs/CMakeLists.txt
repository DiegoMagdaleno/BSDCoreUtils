add_executable(xargs xargs.c strnsubst.c)

target_link_libraries(xargs PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/xargs.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/xargs.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
