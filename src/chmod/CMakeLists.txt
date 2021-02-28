include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/symlink.cmake)
add_executable(chmod chmod.c)

target_link_libraries(chmod PRIVATE compat)
#target_link_libraries(chmod PRIVATE fts)

install_symlink(${CMAKE_INSTALL_PREFIX}/bin/chmod ${CMAKE_INSTALL_PREFIX}/bin/chgrp)
install_symlink(${CMAKE_INSTALL_PREFIX}/bin/chmod ${CMAKE_INSTALL_PREFIX}/sbin/chown)

INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/chmod.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/chgrp.1 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man1)
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/chown.8 DESTINATION ${CMAKE_INSTALL_PREFIX}/man/man8)
