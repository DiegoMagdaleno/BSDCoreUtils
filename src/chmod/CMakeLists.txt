include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/symlink.cmake)

add_executable(chmod chmod.c)

target_link_libraries(chmod PRIVATE compat)
if ( FTS_FOUND )
target_link_libraries(chmod PRIVATE ${OPTLIBS})
endif()

INSTALL(TARGETS chmod DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(chmod PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/chmod ${CMAKE_INSTALL_PREFIX}/bin/chgrp)
install_symlink(${CMAKE_INSTALL_PREFIX}/bin/chmod ${CMAKE_INSTALL_PREFIX}/sbin/chown)


FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)

FILE(GLOB MAN8_FILES *.8)
IF(MAN8_FILES)
    INSTALL(FILES ${MAN8_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man8 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)
