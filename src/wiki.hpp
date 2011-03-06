#ifndef WIKI_H
#define WIKI_H

#include <archive.hpp>
#include <string>
#include <vector>

/**Wiki for any quote reader.
  **/
class Wiki: public Archive
{
public:
	Wiki (std::string file);
	~Wiki ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
