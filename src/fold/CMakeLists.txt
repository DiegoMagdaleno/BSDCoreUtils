
add_executable(fold fold.c)

target_link_libraries(fold PRIVATE compat)

# TODO: Make this target local only
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE")
endif()

INSTALL(TARGETS fold DESTINATION ${CMAKE_INSTALL_BINDIR})
set_target_properties(fold PROPERTIES PREFIX ${PROGRAM_PREFIX})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)