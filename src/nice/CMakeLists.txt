add_executable(nice nice.c)

target_link_libraries(nice PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/nice.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
