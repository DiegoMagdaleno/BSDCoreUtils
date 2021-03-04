include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(join join.c)

target_link_libraries(join PRIVATE compat)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/join.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(TARGETS join DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/join.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)