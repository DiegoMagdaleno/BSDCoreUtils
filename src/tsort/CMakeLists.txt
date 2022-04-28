

add_executable(tsort tsort.c)

target_link_libraries(tsort PRIVATE compat)

target_compile_options(tsort PRIVATE -Wall -Wno-char-subscripts -Wstrict-prototypes -pedantic)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(tsort PRIVATE -D_GNU_SOURCE)
endif()

INSTALL(TARGETS tsort DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(tsort PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)