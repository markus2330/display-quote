#ifndef ARCHIVE_HPP
#define ARCHIVE_HPP

#include <string>
#include <vector>

class Archive
{
public:
	/**Loads archive (positions)
	  *and make everything ready
	  *for random access */
	Archive(std::string filename);
	/**If any setup needs to be
	  *undone, do it here */
	~Archive();

	/**TODO private:
	  *the underlying information
	  to access */
	std::vector<std::string> quotes;
};

#endif
