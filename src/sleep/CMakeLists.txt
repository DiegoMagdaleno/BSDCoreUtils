add_executable(sleep sleep.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/sleep.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
