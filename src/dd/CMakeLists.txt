
add_executable(dd conv.c conv_tab.c dd.c misc.c position.c args.c)

target_link_libraries(dd PRIVATE compat)

INSTALL(TARGETS dd DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(dd PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)