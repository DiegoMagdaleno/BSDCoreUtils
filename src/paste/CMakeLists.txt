add_executable(paste paste.c)

target_link_libraries(paste PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/paste.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/paste.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
