add_executable(mkdir mkdir.c)

target_link_libraries(mkdir PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mkdir.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)