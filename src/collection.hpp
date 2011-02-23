#ifndef COLLECTION_HPP
#define COLLECTION_HPP

#include <iostream>
#include <vector>

class Archive;

/**The public interface to access a collection
  *of archives.*/
class Collection
{
public:
	/**Open access to various archives.*/
	Collection(std::string profile = "default");

	/**Close the opened archives and delete them.*/
	~Collection();

	/**Get a random quote of any archive
	  *and output it to the given stream.*/
	void getRandomQuote(std::ostream &os);
private:
	std::vector<Archive*> archives;
};

#endif
