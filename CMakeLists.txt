cmake_minimum_required(VERSION 3.16)
project(bsdcoreutils)

set(CMAKE_C_STANDARD 11)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Check for the required additional libraries required on Linux
# since onn macOS we use Apple's crypto and native BSD functions
# we don't really need to use any additional libs.
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Looking for required package OpenSSL")
    find_package(OpenSSL REQUIRED)
    message("Looking for required package libbsd")
    pkg_check_modules(BSD_OVERLAY REQUIRED libbsd-overlay)    
    find_package(FTS)
    if ( FTS_FOUND )
        message("Using FTS implementation")
        list(APPEND OPTLIBS ${FTS_LIBRARY})
        include_directories(BEFORE ${FTS_INCLUDE_DIR})
    endif()
    add_definitions("-DDEFFILEMODE=(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)")
    add_definitions("-DACCESSPERMS=(S_IRWXU|S_IRWXG|S_IRWXO)")
endif()

add_subdirectory(compat)
add_subdirectory(src) 