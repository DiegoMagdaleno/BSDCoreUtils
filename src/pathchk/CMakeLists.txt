add_executable(pathchk pathchk.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/pathchk.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
