
add_executable(date date.c)

target_link_libraries(date PRIVATE compat)
target_link_libraries(date PRIVATE util)

target_compile_definitions(date PRIVATE -D_DEFAULT_SOURCE)
target_compile_definitions(date PRIVATE -D_XOPEN_SOURCE)

INSTALL(TARGETS date DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(date PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)