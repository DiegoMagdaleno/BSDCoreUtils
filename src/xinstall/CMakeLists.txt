include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(xinstall xinstall.c)

target_link_libraries(xinstall PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/install.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS xinstall DESTINATION ${CMAKE_INSTALL_BINDIR})


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/install.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
