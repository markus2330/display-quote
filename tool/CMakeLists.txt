add_executable(dfc main.cpp)

include_directories (${PROJECT_SOURCE_DIR}/src)
link_directories (${PROJECT_BINARY_DIR}/src)

target_link_libraries (dfc fortune)

install (TARGETS dfc DESTINATION bin)
