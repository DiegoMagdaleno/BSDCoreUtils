add_executable(mknod mknod.c)

target_link_libraries(mknod PRIVATE compat)

if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -D_GNU_SOURCE")
endif()

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/mknod ${CMAKE_INSTALL_PREFIX}/bin/mkfifo)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mkfifo.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/mknod.8 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man8)