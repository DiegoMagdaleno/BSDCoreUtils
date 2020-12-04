add_executable(fmt fmt.c)

target_link_libraries(fmt PRIVATE compat)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_XOPEN_SOURCE")

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
else()
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DEFAULT_SOURCE")
endif()

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/fmt.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)