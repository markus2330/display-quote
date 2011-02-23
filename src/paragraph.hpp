#ifndef PARAGRAPH
#define PARAGRAPH

#include <archive.hpp>
#include <string>
#include <vector>

/**A paragraph based quote reader.
  *Every new paragraph (starting with
  *a blank line) is considered to be
  *a quote.*/
class Paragraph: public Archive
{
public:
	Paragraph (std::string file);
	~Paragraph ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
