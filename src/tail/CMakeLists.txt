
add_executable(tail tail.c misc.c read.c reverse.c forward.c)

target_link_libraries(tail PRIVATE compat)
target_include_directories(tail PRIVATE ${EVENT_INCLUDE_DIRS})
target_link_libraries(tail PRIVATE ${EVENT_LIBRARIES})

INSTALL(TARGETS tail DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(tail PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN8_FILES *.1)
IF(MAN8_FILES)
    INSTALL(FILES ${MAN8_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)