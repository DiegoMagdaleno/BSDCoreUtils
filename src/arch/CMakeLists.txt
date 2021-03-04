include(${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/manpage.cmake)

add_executable(arch arch.c)

INSTALL(TARGETS arch DESTINATION ${CMAKE_INSTALL_BINDIR})

INSTALL_MANPAGE(arch.1)