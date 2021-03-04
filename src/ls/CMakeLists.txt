
add_executable(ls ls.c main.c utf8.c util.c print.c cmp.c)

target_link_libraries(ls PRIVATE compat)
target_link_libraries(ls PRIVATE ncurses)
target_link_libraries(ls PRIVATE util)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE")
endif()

INSTALL(TARGETS ls DESTINATION ${CMAKE_INSTALL_BINDIR})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)