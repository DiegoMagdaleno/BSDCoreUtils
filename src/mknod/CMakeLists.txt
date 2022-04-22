
add_executable(mknod mknod.c)

target_link_libraries(mknod PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(mknod PRIVATE -D_GNU_SOURCE)
endif()

INSTALL(TARGETS mknod DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(mknod PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/mknod ${CMAKE_INSTALL_PREFIX}/bin/mkfifo)

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