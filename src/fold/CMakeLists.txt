
add_executable(fold fold.c)

target_link_libraries(fold PRIVATE compat)

target_compile_definitions(fold PRIVATE -D_XOPEN_SOURCE)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_compile_definitions(fold PRIVATE -D_GNU_SOURCE)
else()
    target_compile_definitions(fold PRIVATE -D_DEFAULT_SOURCE)
endif()

INSTALL(TARGETS fold DESTINATION ${CMAKE_INSTALL_BINDIR})

if(PROGRAM_PREFIX)
set_target_properties(fold PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)