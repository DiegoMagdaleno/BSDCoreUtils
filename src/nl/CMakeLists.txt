add_executable(nl nl.c)

target_link_libraries(nl PRIVATE compat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/nl.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
