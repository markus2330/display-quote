add_executable(dq main.cpp)

include_directories (${ELEKTRA_INCLUDE_DIR})
include_directories (${PROJECT_SOURCE_DIR}/src)

link_directories (${PROJECT_BINARY_DIR}/src)

target_link_libraries (dq fortune)
target_link_libraries (dq ${ELEKTRA_LIBRARY})

install (TARGETS dq DESTINATION bin)
