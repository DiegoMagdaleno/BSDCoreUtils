
add_executable(du du.c)

target_link_libraries(du PRIVATE compat)
if ( FTS_FOUND )
target_link_libraries(du PRIVATE ${OPTLIBS})
endif()

INSTALL(TARGETS du DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(du PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)