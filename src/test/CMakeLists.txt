add_executable(test test.c)

target_link_libraries(test PRIVATE compat)

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/test ${CMAKE_INSTALL_PREFIX}/bin/])
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/test.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
