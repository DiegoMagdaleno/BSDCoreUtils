
add_executable(id id.c)

target_link_libraries(id PRIVATE compat)

INSTALL(TARGETS id DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(id PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/id ${CMAKE_INSTALL_PREFIX}/bin/groups)
install_symlink(${CMAKE_INSTALL_PREFIX}/bin/id ${CMAKE_INSTALL_PREFIX}/sbin/whoami)

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)