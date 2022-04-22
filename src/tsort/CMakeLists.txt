

add_executable(tsort tsort.c)

target_link_libraries(tsort PRIVATE compat)

# TODO: Make this target local only
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-char-subscripts -Wstrict-prototypes -pedantic")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
endif()

INSTALL(TARGETS tsort DESTINATION ${CMAKE_INSTALL_BINDIR})
set_target_properties(tsort PROPERTIES PREFIX ${PROGRAM_PREFIX})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)