add_executable(wc wc.c)

target_link_libraries(wc PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/wc.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
