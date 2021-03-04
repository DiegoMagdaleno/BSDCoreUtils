add_executable(sort bwstring.c coll.c file.c mem.c radixsort.c sort.c vsort.c commoncrypto.c)

target_link_libraries(sort PRIVATE compat)
target_link_libraries(sort PRIVATE OpenSSL::Crypto)
target_link_libraries(sort PRIVATE ncurses)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(sort PRIVATE pthread)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")

INSTALL(TARGETS sort DESTINATION ${CMAKE_INSTALL_BINDIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sort.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/sort.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
