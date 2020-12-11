add_executable(readlink readlink.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/readlink.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
