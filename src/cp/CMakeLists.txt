
add_executable(cp cp.c utils.c)

target_link_libraries(cp PRIVATE compat)

if(PROGRAM_PREFIX)
set_target_properties(cp PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

INSTALL(TARGETS cp DESTINATION ${CMAKE_INSTALL_BINDIR})
if (FTS_FOUND)
target_link_libraries(cp PRIVATE ${OPTLIBS})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)