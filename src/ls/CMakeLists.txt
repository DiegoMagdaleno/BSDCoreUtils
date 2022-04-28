
add_executable(ls ls.c main.c utf8.c util.c print.c cmp.c)

target_link_libraries(ls PRIVATE compat)
target_link_libraries(ls PRIVATE ncurses)
target_link_libraries(ls PRIVATE util)
if ( FTS_FOUND )
target_link_libraries(ls PRIVATE ${OPTLIBS})
endif()

target_compile_definitions(ls PRIVATE -D_XOPEN_SOURCE)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(ls PRIVATE -D_GNU_SOURCE)
else()
    target_compile_definitions(ls PRIVATE -D_DEFAULT_SOURCE)
endif()

INSTALL(TARGETS ls DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(ls PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)