add_executable(dd conv.c conv_tab.c dd.c misc.c position.c args.c)

target_link_libraries(dd PRIVATE compat)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/dd.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)