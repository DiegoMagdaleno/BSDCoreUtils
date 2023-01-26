cmake_minimum_required(VERSION 3.25)
project(bsdcoreutils)

set(CMAKE_C_STANDARD 11)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules/")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# CMAKE Doesn't really have a Macro to detect Linux, Why?
if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    set(LINUX TRUE)
endif()

include(utils)
include(ExternalProject)

# Check for the required additional libraries required on Linux
# since onn macOS we use Apple's crypto and native BSD functions
# we don't really need to use any additional libs.
if(LINUX)
    set(WITH_EXTERNAL_FTS FALSE)
    message("Looking for required package OpenSSL")
    find_package(OpenSSL REQUIRED)
    set(is_musl_test FALSE)
    is_musl_c(is_musl_test)
    if(is_musl_test)
        find_package(FTS)
        if ( FTS_FOUND )
            message("Using FTS implementation")
            list(APPEND OPTLIBS ${FTS_LIBRARY})
            include_directories(BEFORE ${FTS_INCLUDE_DIR})
            set(WITH_EXTERNAL_FTS TRUE)
        else()
            include(FindAutotools)
            message("Couldn't find external FTS implementation, will try to build one")
            set(FTS_LIBRARY ${CMAKE_INSTALL_PREFIX}/lib/${CMAKE_STATIC_LIBRARY_PREFIX}fts${CMAKE_STATIC_LIBRARY_SUFFIX})
            find_program(MAKE_EXECUTABLE NAMES gmake make REQUIRED)
            ExternalProject_Add(libfts
            GIT_REPOSITORY https://github.com/pullmoll/musl-fts.git
            GIT_TAG v1.2.7
            UPDATE_DISCONNECTED TRUE
            CONFIGURE_HANDLED_BY_BUILD TRUE
            CONFIGURE_COMMAND <SOURCE_DIR>/configure
            BUILD_COMMAND ${MAKE_EXECUTABLE} -j
            INSTALL_COMMAND ${MAKE_EXECUTABLE} -j install
            TEST_COMMAND ""
            BUILD_BYPRODUCTS ${FTS_LIBRARY}
            )
            ExternalProject_Add_Step(libfts
            bootstrap
            COMMAND <SOURCE_DIR>/bootstrap.sh
            DEPENDEES download
            DEPENDEES configure
            )
            set(WITH_EXTERNAL_FTS TRUE)
        endif()
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