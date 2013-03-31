project (dfc)

cmake_minimum_required(VERSION 2.6)

find_package (Elektra REQUIRED)

if (CMAKE_COMPILER_IS_GNUCXX)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++98 -Wall -Wextra -Wno-missing-field-initializers")
	message (STATUS "G++ detected, compile flags: ${CMAKE_CXX_FLAGS}")
endif (CMAKE_COMPILER_IS_GNUCXX)

add_subdirectory(src)
add_subdirectory(tool)

set (CPACK_PACKAGE_NAME "dq")
set (CPACK_PACKAGE_VERSION "0.3")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY
"display-quote (short: dq) prints a text from a configured collection.")
set (CPACK_PACKAGE_CONTACT "contact@markus-raab.org")
set (CPACK_SOURCE_IGNORE_FILES "/.gitignore")
set (CPACK_PACKAGE_EXECUTABLES dq)

set (CPACK_GENERATOR "DEB")
set (CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
set (CPACK_DEBIAN_PACKAGE_SECTION "libs")
set (CPACK_DEBIAN_PACKAGE_RECOMMENDS "")

set (CPACK_PACKAGE_ARCHITECTURE amd64)

set (CPACK_SYSTEM_NAME "Debian-amd64")

include (CPack)
