#ifndef LINES_H
#define LINES_H

#include <archive.hpp>
#include <string>
#include <vector>

/**Lines for any quote reader.
  **/
class Lines: public Archive
{
public:
	Lines (std::string file);
	~Lines ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
