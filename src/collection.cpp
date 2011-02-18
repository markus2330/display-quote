#include <collection.hpp>
#include <iostream>

#include <archive.hpp>
#include <quotes.hpp>
#include <dhammapada.hpp>

#include <stdlib.h>
#include <time.h>

Collection::Collection()
{
	srand (time(0));

	int r = (int) ((double)3*rand()/RAND_MAX);

	switch (r)
	{
	case 0: archive = new Quotes ("/home/markus/Info/quote");
		break;
	case 1: archive = new Dhammapada ("/usr/share/doc/display-dhammapada/dhammapada-english-transl.txt");
		break;
	default: throw "no archive in that case";
	}
}

Collection::~Collection()
{
	delete archive;
}

void Collection::getRandomQuote(std::ostream &os)
{

	/*Erzeugt eine Zahl zwischen 0 und size-1*/
	int r = (int) ((double)archive->size()*rand()/RAND_MAX);

	os << archive->operator[](r);
}
