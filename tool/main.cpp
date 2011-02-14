#include <iostream>
#include <archive.hpp>

int main()
{
	std::cout << "Usage: dfc [profile]" << std::endl << std::endl;
	Archive a("/tmp/test.txt");

	std::cout << "Parsing finished" << std::endl << std::endl;

	for (int i=0; i<a.quotes.size(); ++i)
	{
		std::cout << i+1 << ": " << a.quotes[i]
			<< std::endl << std::endl;
	}
}
