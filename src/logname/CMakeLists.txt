add_executable(logname logname.c)

target_link_libraries(logname PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/logname.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)