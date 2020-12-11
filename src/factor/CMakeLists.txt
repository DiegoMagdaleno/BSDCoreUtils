add_executable(factor factor.c pattern.c pr_tbl.c)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/factor.6 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man6)