
add_executable(comm comm.c)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(comm PRIVATE compat)
    target_compile_definitions(comm PRIVATE -D__USE_POSIX2)
endif()

INSTALL(TARGETS comm DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(comm PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)