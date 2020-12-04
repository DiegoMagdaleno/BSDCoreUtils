add_executable(split split.c)

target_link_libraries(split PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/split.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
