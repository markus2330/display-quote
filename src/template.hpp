#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <archive.hpp>
#include <string>
#include <vector>

/**Template for any quote reader.
  **/
class Template: public Archive
{
public:
	Template (std::string file);
	~Template ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
