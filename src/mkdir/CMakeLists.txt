include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(mkdir mkdir.c)

target_link_libraries(mkdir PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/mkdir.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS mkdir DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mkdir.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)