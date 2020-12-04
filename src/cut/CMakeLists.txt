add_executable(cut cut.c)

target_link_libraries(cut PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/cut.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)