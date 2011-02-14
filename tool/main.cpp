#include <iostream>
#include <collection.hpp>

int main()
{
	std::cout << "Usage: dfc [profile]" << std::endl;
	Collection c;
	c.getRandomQuote(std::cout);
}
