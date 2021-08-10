# - Try to find FTS library and headers
#
# Usage of this module as follows:
#
#  find_package(FTS)
#
# Variables used by this module, they can change the default behaviour and need
# to be set before calling find_package:
#
#  FTS_ROOT_DIR           Set this variable to the root installation of
#                         FTS if the module has problems finding the
#                         proper installation path.
#
# Variables defined by this module:
#
#  FTS_FOUND              System has FTS library
#  FTS_LIBRARY            The FTS library
#  FTS_INCLUDE_DIR        The FTS headers

find_path(FTS_ROOT_DIR
    NAMES include/fts.h
)

find_library(FTS_LIBRARY
    NAMES fts
    HINTS ${FTS_ROOT_DIR}/lib
)

find_path(FTS_INCLUDE_DIR
    NAMES fts.h
    HINTS ${FTS_ROOT_DIR}/include
)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(FTS DEFAULT_MSG
    FTS_LIBRARY
    FTS_INCLUDE_DIR
)

mark_as_advanced(
    FTS_ROOT_DIR
    FTS_LIBRARY
    FTS_INCLUDE_DIR
)