add_executable(split split.c)

target_link_libraries(split PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/split.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/split.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
