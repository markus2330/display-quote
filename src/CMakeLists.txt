set (SOURCES collection.cpp collection.hpp archive.cpp archive.hpp
	dhammapada.hpp dhammapada.cpp quotes.hpp quotes.cpp
	paragraph.hpp paragraph.cpp)

include_directories (${Elektra_INCLUDE_DIR})
include_directories (${PROJECT_SOURCE_DIR}/src)
add_library (fortune SHARED ${SOURCES})
target_link_libraries (fortune ${Elektra_LIBRARIES})

install (TARGETS fortune DESTINATION lib)
