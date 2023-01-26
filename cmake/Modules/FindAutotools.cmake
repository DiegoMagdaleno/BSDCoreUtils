# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#[=======================================================================[.rst:
FindAutotools
-------------

The main purpose is to detect that commonly used Autotools programs are isntalled.
This lets the user know at CMake configuration time if the computer is ready to
build an autotools-based ExternalProject.

Result Variables
^^^^^^^^^^^^^^^^

``Autotools_FOUND``
  indicates Autotools and associated programs are detected
#]=======================================================================]

find_program(AUTOCONF_EXECUTABLE
NAMES autoconf
DOC "Autoconf")

if(AUTOCONF_EXECUTABLE)
  execute_process(COMMAND ${AUTOCONF_EXECUTABLE} --version
  RESULT_VARIABLE ret
  OUTPUT_VARIABLE out
  )
  message(DEBUG "${out}")
  if(ret EQUAL 0)
    string(REGEX MATCH "autoconf .*([0-9]+\\.[0-9]+)" _m "${out}")
    set(AUTOCONF_VERSION "${CMAKE_MATCH_1}")
  endif()
endif()

find_program(AUTOMAKE_EXECUTABLE
NAMES automake
DOC "Automake")

find_program(LIBTOOL_EXECUTABLE
NAMES glibtool libtool
NAMES_PER_DIR
DOC "libtool"
)

find_program(M4_EXECUTABLE
NAMES gm4 m4
NAMES_PER_DIR
DOC "M4"
)

find_program(MAKE_EXECUTABLE
NAMES gmake make
NAMES_PER_DIR
DOC "GNU Make")


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Autotools
VERSION_VAR AUTOCONF_VERSION
REQUIRED_VARS AUTOCONF_EXECUTABLE AUTOMAKE_EXECUTABLE MAKE_EXECUTABLE
)