
add_executable(mv mv.c rm.c cp.c)

target_link_libraries(mv PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DARWIN_SOURCE")
endif()

if ( FTS_FOUND )
target_link_libraries(mv PRIVATE ${OPTLIBS})
endif()

INSTALL(TARGETS mv DESTINATION ${CMAKE_INSTALL_BINDIR})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)