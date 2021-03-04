include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)


add_executable(head head.c)

target_link_libraries(head PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/head.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS head DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/head.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)