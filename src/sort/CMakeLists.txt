
add_executable(sort bwstring.c coll.c file.c mem.c radixsort.c sort.c vsort.c commoncrypto.c)

target_link_libraries(sort PRIVATE compat)
target_link_libraries(sort PRIVATE OpenSSL::Crypto)
target_link_libraries(sort PRIVATE ncurses)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(sort PRIVATE pthread)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(TARGETS sort DESTINATION ${CMAKE_INSTALL_BINDIR})

FILE(GLOB MAN1_FILES *.1)
IF(MAN1_FILES)
    INSTALL(FILES ${MAN1_FILES} DESTINATION ${INSTALL_MANDIR}/man1 COMPONENT ManPages)
ENDIF()
FILE(GLOB MAN)