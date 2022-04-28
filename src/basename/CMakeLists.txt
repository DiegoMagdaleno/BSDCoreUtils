
add_executable(basename basename.c)

INSTALL(TARGETS basename DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(basename PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

if(WIN32)
target_link_libraries(basename PRIVATE compat)
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)