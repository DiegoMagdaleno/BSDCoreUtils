add_executable(cp cp.c utils.c)

target_link_libraries(cp PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/cp.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)