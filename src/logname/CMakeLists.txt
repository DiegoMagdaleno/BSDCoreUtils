
add_executable(logname logname.c)

target_link_libraries(logname PRIVATE compat)

INSTALL(TARGETS logname DESTINATION ${CMAKE_INSTALL_BINDIR})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)