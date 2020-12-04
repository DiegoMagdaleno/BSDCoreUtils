add_executable(yes yes.c)

target_link_libraries(yes PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/yes.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
