
add_executable(unexpand unexpand.c)

INSTALL(TARGETS unexpand DESTINATION ${CMAKE_INSTALL_BINDIR})

target_link_libraries(unexpand.c PRIVATE compat)
