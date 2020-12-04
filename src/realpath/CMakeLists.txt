add_executable(realpath realpath.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/realpath.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)