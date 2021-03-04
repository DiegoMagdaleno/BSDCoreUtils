add_executable(who who.c utmpentry.c)

target_link_libraries(who PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSUPPORT_UTMP")
endif()

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSUPPORT_UTMPX")
endif()

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/who.1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/who.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
