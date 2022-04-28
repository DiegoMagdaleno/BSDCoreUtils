
add_executable(rm rm.c)

target_link_libraries(rm PRIVATE compat)

INSTALL(TARGETS rm DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(rm PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

if ( FTS_FOUND )
target_link_libraries(rm PRIVATE ${OPTLIBS})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)