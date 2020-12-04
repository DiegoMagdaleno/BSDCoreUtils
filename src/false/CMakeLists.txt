add_executable(false false.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/false.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)