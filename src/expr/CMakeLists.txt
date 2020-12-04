add_executable(expr expr.c)

target_link_libraries(expr PRIVATE compat)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/expr.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)