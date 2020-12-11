add_executable(mv mv.c rm.c cp.c)

target_link_libraries(mv PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_DARWIN_SOURCE")
endif()

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mv.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)