set (SOURCES collection.cpp collection.hpp archive.cpp archive.hpp
	dhammapada.hpp dhammapada.cpp quotes.hpp quotes.cpp
	paragraph.hpp paragraph.cpp lines.hpp lines.cpp
	wiki.hpp wiki.cpp task.hpp task.cpp)

include_directories (${ELEKTRA_INCLUDE_DIR})
include_directories (${PROJECT_SOURCE_DIR}/src)
add_library (fortune SHARED ${SOURCES})
target_link_libraries (fortune ${ELEKTRA_LIBRARY})

install (TARGETS fortune DESTINATION lib)
