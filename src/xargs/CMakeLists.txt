add_executable(xargs xargs.c strnsubst.c)

target_link_libraries(xargs PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/xargs.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
