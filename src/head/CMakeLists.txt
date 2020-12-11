add_executable(head head.c)

target_link_libraries(head PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/head.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)