list(APPEND Win2Posix 
    src/err_translate.c
    src/dirent.c
    src/err.c)

add_library(win2posix
    ${Win2Posix})

target_include_directories(win2posix PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
