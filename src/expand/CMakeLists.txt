add_executable(expand expand.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/expand.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)