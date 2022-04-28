
add_executable(unexpand unexpand.c)

INSTALL(TARGETS unexpand DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(unexpand PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

target_link_libraries(unexpand.c PRIVATE compat)
