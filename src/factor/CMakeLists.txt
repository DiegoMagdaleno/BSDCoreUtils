
add_executable(factor factor.c pattern.c pr_tbl.c)

target_link_libraries(factor PRIVATE compat)

INSTALL(TARGETS factor DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(factor PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN6_FILES *.6)
IF(MAN6_FILES)
    INSTALL(FILES ${MAN6_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man6 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)