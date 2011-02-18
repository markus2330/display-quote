#ifndef QUOTES
#define QUOTES

#include <archive.hpp>
#include <string>
#include <vector>

class Quotes: public Archive
{
public:
	Quotes (std::string file);
	~Quotes ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
