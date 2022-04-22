
add_executable(join join.c)

target_link_libraries(join PRIVATE compat)


# TODO: Make this target local only
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE -D_XOPEN_SOURCE")
endif()

INSTALL(TARGETS join DESTINATION ${CMAKE_INSTALL_BINDIR})
set_target_properties(join PROPERTIES PREFIX ${PROGRAM_PREFIX})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)