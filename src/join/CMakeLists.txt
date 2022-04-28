
add_executable(join join.c)

target_link_libraries(join PRIVATE compat)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
target_compile_definitions(join PRIVATE -D_XOPEN_SOURCE)
target_compile_definitions(join PRIVATE -D_DEFAULT_SOURCE)
endif()

INSTALL(TARGETS join DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(join PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)