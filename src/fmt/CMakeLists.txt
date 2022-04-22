
add_executable(fmt fmt.c)

target_link_libraries(fmt PRIVATE compat)

target_compile_definitions(fmt PRIVATE -D_XOPEN_SOURCE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(fmt PRIVATE -D_GNU_SOURCE)
else()
    target_compile_definitions(fmt PRIVATE -D_DEFAULT_SOURCE)
endif()

INSTALL(TARGETS fmt DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(fmt PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)