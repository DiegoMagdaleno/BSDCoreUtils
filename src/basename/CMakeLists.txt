add_executable(basename basename.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/cat.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)