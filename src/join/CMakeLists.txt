add_executable(join join.c)

target_link_libraries(join PRIVATE compat)


if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
endif()

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/join.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)