
add_executable(sort bwstring.c coll.c file.c mem.c radixsort.c sort.c vsort.c commoncrypto.c)

target_link_libraries(sort PRIVATE compat)
if(NOT APPLE)
    target_link_libraries(sort PRIVATE OpenSSL::Crypto)
endif()
if (APPLE)
    target_link_libraries(sort PRIVATE "-framework Security")
endif()

target_link_libraries(sort PRIVATE ncurses)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(sort PRIVATE pthread)
endif()

target_compile_definitions(sort PRIVATE -D_GNU_SOURCE)

INSTALL(TARGETS sort DESTINATION ${CMAKE_INSTALL_BINDIR})
if(PROGRAM_PREFIX)
set_target_properties(sort PROPERTIES PREFIX ${PROGRAM_PREFIX})
endif()

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${CMAKE_INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)