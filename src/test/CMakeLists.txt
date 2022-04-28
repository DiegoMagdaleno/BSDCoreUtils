
add_executable(test test.c)

target_link_libraries(test PRIVATE compat)

INSTALL(TARGETS test DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(test PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/test ${CMAKE_INSTALL_PREFIX}/bin/])

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)