cmake_minimum_required(VERSION 3.25)
project(bsdcoreutils)

set(CMAKE_C_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# CMAKE Doesn't really have a Macro to detect Linux, Why?
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
endif()

set(WITH_EXTERNAL_FTS FALSE)

# Check for the required additional libraries required on Linux
# since onn macOS we use Apple's crypto and native BSD functions
# we don't really need to use any additional libs.
if(LINUX)
    include(utils)
    message("Looking for required package OpenSSL")
    find_package(OpenSSL REQUIRED)
    set(is_musl_test FALSE)
    is_musl_c(is_musl_test)
    if(is_musl_test)
        # Just build our own version of the fts library in Musl, is always statically linked per the readme, so there is no problem
        add_subdirectory(libfts)
        set(WITH_EXTERNAL_FTS TRUE)
    endif()
    add_definitions("-DDEFFILEMODE=(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)")
    add_definitions("-DACCESSPERMS=(S_IRWXU|S_IRWXG|S_IRWXO)")
    add_definitions(-DREG_STARTEND=0)
    # Should we really define it as 512?
    add_definitions(-DS_BLKSIZE=512)
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