
add_executable(rm rm.c)

target_link_libraries(rm PRIVATE compat)

INSTALL(TARGETS rm DESTINATION ${CMAKE_INSTALL_BINDIR})

if ( FTS_FOUND )
target_link_libraries(rm PRIVATE ${OPTLIBS})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)