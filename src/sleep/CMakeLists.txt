
add_executable(sleep sleep.c)

INSTALL(TARGETS sleep DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(sleep PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)