add_executable(tsort tsort.c)

target_link_libraries(tsort PRIVATE compat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-char-subscripts -Wstrict-prototypes -pedantic")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/tsort.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})


INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/tsort.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
