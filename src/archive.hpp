#ifndef ARCHIVE_HPP
#define ARCHIVE_HPP

#include <string>
#include <vector>

class Archive
{
public:
	/**Loads archive (positions)
	  *and make everything ready
	  *for random access.
	  *TODO: should be map<string> */
	// Archive(std::string filename);

	/**If any setup needs to be
	  *undone, do it here */
	virtual ~Archive() = 0;

	/**Return a const reference to
	  *a quote by a given index.
	  *The index is a number from 0
	  *to size()-1.*/
	virtual const std::string& operator [] (int index) const = 0;

	/**Return how many quotes
	  *are available in the
	  *Archive.*/
	virtual int size() const = 0;
};

#endif
