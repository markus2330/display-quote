#include <collection.hpp>
#include <iostream>

#include <archive.hpp>

#include <stdlib.h>
#include <time.h>

Collection::Collection()
{
	archive = new Archive ("/usr/share/doc/display-dhammapada/dhammapada-english-transl.txt");
}

Collection::~Collection()
{
	delete archive;
}

void Collection::getRandomQuote(std::ostream &os)
{

	srand (time(0));

	/*Erzeugt eine Zahl zwischen 0 und size-1*/
	int r = (int) ((double)archive->size()*rand()/RAND_MAX);

	os << archive->operator[](r);
}
