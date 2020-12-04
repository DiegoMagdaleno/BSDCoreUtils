add_executable(printf printf.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/printf.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
