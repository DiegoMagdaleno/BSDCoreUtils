include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(true true.c)

target_link_libraries(true PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/true.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS true DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/true.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
