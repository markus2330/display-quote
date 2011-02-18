set (SOURCES collection.cpp collection.hpp archive.cpp archive.hpp
	dhammapada.hpp dhammapada.cpp quotes.hpp quotes.cpp)

include_directories (${PROJECT_SOURCE_DIR}/src)
add_library (fortune SHARED ${SOURCES})

install (TARGETS fortune DESTINATION lib)
