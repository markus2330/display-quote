project (dfc)

cmake_minimum_required(VERSION 2.6)

find_package (Elektra REQUIRED)

add_subdirectory(src)
add_subdirectory(tool)

set (CPACK_PACKAGE_NAME "dfc")
set (CPACK_PACKAGE_VERSION "0.1")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY
"display-from-collection (short: dfc) prints a text from a configured collection.")
set (CPACK_PACKAGE_CONTACT "contact@markus-raab.org")
set (CPACK_SOURCE_IGNORE_FILES "/.gitignore")
set (CPACK_PACKAGE_EXECUTABLES dfc)

set (CPACK_GENERATOR "DEB")
set (CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set (CPACK_DEBIAN_PACKAGE_SECTION "libs")
set (CPACK_DEBIAN_PACKAGE_RECOMMENDS "")

set (CPACK_PACKAGE_ARCHITECTURE amd64)

set (CPACK_SYSTEM_NAME "Debian-amd64")

include (CPack)
