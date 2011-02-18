#ifndef DHAMMAPADA
#define DHAMMAPADA

#include <archive.hpp>
#include <string>
#include <vector>

class Dhammapada : public Archive
{
public:
	/**Loads Dhammapada (positions)
	  *and make everything ready
	  *for random access */
	Dhammapada(std::string filename);

	/**If any setup needs to be
	  *undone, do it here */
	~Dhammapada();

	/**Return a const reference to
	  *a quote by a given index.
	  *The index is a number from 0
	  *to size()-1.*/
	const std::string& operator [] (int index) const;

	/**Return how many quotes
	  *are available in the
	  *Dhammapada.*/
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};


#endif
