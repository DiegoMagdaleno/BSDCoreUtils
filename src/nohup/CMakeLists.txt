add_executable(nohup nohup.c)

target_link_libraries(nohup PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/nohup.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
