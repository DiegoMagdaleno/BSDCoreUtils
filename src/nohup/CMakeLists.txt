include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(nohup nohup.c)

target_link_libraries(nohup PRIVATE compat)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/nohup.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS nohup DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/nohup.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
