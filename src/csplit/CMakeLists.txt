add_executable(csplit csplit.c)

target_link_libraries(csplit PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/csplit.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/csplit.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)