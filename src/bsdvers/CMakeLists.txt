add_executable(bsdvers bsdvers.c)

INSTALL(TARGETS bsdvers DESTINATION ${CMAKE_INSTALL_BINDIR})
