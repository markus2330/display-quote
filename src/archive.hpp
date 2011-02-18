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

	/**Return a const reference to
	  *a quote by a given index.
	  *The index is a number from 0
	  *to size()-1.*/
	const std::string& operator [] (int index) const;

	/**Return how many quotes
	  *are available in the
	  *Archive.*/
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
