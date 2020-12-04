add_executable(uname uname.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/uname.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
