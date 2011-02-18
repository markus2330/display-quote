#include <collection.hpp>
#include <iostream>

#include <archive.hpp>

#include <stdlib.h>
#include <time.h>

Collection::Collection()
{}

Collection::~Collection()
{}

void Collection::getRandomQuote(std::ostream &os)
{
	Archive a("/usr/share/doc/display-dhammapada/dhammapada-english-transl.txt");

	srand (time(0));

	int r = (int) ((double)a.size()*rand()/RAND_MAX);

	os << a[r];
}
