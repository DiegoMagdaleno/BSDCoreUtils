add_executable(rmdir rmdir.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/rmdir.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
