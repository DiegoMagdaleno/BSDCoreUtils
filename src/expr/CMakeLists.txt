
add_executable(expr expr.c)

target_link_libraries(expr PRIVATE compat)

target_compile_definitions(expr PRIVATE -D_GNU_SOURCE)

INSTALL(TARGETS expr DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(expr PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)