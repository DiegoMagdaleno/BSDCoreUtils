add_executable(pr pr.c egetopt.c)

target_link_libraries(pr PRIVATE compat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/pr.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
