
add_executable(pr pr.c egetopt.c)

target_link_libraries(pr PRIVATE compat)

# TODO: Make this target local only
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(TARGETS pr DESTINATION ${CMAKE_INSTALL_BINDIR})
set_target_properties(pr PROPERTIES PREFIX ${PROGRAM_PREFIX})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)