add_executable(true true.c)

target_link_libraries(true PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/true.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
