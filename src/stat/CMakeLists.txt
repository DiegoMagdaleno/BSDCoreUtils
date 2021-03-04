include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(stat stat.c)

target_link_libraries(stat PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/stat.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS stat DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/stat.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
