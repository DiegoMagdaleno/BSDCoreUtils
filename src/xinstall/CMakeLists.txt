add_executable(install xinstall.c)

target_link_libraries(install PRIVATE compat)


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/install.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
