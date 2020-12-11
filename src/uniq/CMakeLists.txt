add_executable(uniq uniq.c)

target_link_libraries(uniq PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/uniq.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
