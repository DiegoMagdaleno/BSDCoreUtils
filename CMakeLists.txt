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
    find_package(FTS)
    if ( FTS_FOUND )
        message("Using FTS implementation")
        list(APPEND OPTLIBS ${FTS_LIBRARY})
        include_directories(BEFORE ${FTS_INCLUDE_DIR})
    else()
        message("Your OS doesn't have a separate FTS implementation, assuming one is provided by the LIBC")
    endif()
    add_definitions("-DDEFFILEMODE=(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)")
    add_definitions("-DACCESSPERMS=(S_IRWXU|S_IRWXG|S_IRWXO)")
    add_definitions(-DREG_STARTEND=0)
    # Should we really define it as 512?
    add_definitions(-DS_BLKSIZE=512)
endif()

# CMAKE Doesn't really have a Macro to detect Linux, Why?
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
set(LINUX TRUE)
endif()

if (WIN32)
    message("Looking for Win32 OpenSSL")
    find_package(OpenSSL REQUIRED)
endif()

set(PROGRAM_PREFIX "" CACHE STRING "Add a prefix to each executable, useful in order to prevent conflicts with default coreutils")
OPTION(USE_LIBWHEREAMI "Use libwhereami in order to reimplement some BSD functions, only recommended on Linux" OFF)


if(USE_LIBWHEREAMI)
    add_subdirectory(libwhereami)
    # TODO: This is wrong
    include_directories("${CMAKE_SOURCE_DIR}/libwhereami/src")
    add_compile_definitions(USE_LIBWHEREAMI)
endif()
add_subdirectory(compat)
if (WIN32)
add_subdirectory(libcompleteme)
add_subdirectory(win2posix)
endif()
add_subdirectory(src)