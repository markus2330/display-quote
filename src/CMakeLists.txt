set (SOURCES collection.cpp collection.hpp)

include_directories (${PROJECT_SOURCE_DIR}/src)
add_library (fortune SHARED ${SOURCES})

install (TARGETS fortune DESTINATION lib)
