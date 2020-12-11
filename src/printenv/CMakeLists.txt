add_executable(printenv printenv.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/printenv.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
