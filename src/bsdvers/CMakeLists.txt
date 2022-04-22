add_executable(bsdvers bsdvers.c)
set_target_properties(bsdvers PROPERTIES PREFIX ${PROGRAM_PREFIX})

INSTALL(TARGETS bsdvers DESTINATION ${CMAKE_INSTALL_BINDIR})
