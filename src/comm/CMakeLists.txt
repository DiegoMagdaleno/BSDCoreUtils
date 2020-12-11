add_executable(comm comm.c)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(comm PRIVATE compat)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D__USE_POSIX2")
endif()

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/comm.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)