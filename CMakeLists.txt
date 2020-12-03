cmake_minimum_required(VERSION 3.16)
project(bsdcoreutils)

set(CMAKE_C_STANDARD 11)

# Check for the required additional libraries required on Windows
# since in macOS we use Apple's crypto and native BSD functions
# we don't really need to use any additonal libs.
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("Looking for required package OpenSSL")
    find_package(OpenSSL REQUIRED)
    message("Looking for required package libbsd")
    pkg_check_modules(BSD_OVERLAY REQUIRED libbsd-overlay)
endif()

add_subdirectory(compat)