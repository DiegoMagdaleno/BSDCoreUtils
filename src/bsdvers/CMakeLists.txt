add_executable(bsdvers bsdvers.c)
if(PROGRAM_PREFIX)
set_target_properties(bsdvers PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

INSTALL(TARGETS bsdvers DESTINATION ${CMAKE_INSTALL_BINDIR})
