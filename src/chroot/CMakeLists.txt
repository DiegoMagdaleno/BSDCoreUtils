
add_executable(chroot chroot.c)

INSTALL(TARGETS chroot DESTINATION ${CMAKE_INSTALL_SBINDIR})

if(PROGRAM_PREFIX)
set_target_properties(chroot PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN8_FILES *.8)
IF(MAN8_FILES)
    INSTALL(FILES ${MAN8_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man8 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)