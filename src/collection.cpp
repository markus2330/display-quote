#include <collection.hpp>
#include <iostream>

#include <archive.hpp>
#include <quotes.hpp>
#include <paragraph.hpp>
#include <dhammapada.hpp>

#include <stdlib.h>
#include <time.h>

#include <kdb>

Collection::Collection(std::string profile)
{
	srand (time(0));

	int r = (int) ((double)3*rand()/RAND_MAX);

	kdb::KDB kdb;

	kdb::Key root("user/sw/dfc", KEY_END);
	root += profile;

	kdb::KeySet config;
	kdb.get(config, root);

	std::cout << "root key is: " << root.name() << std::endl;

	config.rewind();
	std::cout << "size of config: " << config.size() << std::endl;
	kdb::Key k;
	while (k = config.next())
	{
		if (root.isBelow(k))
			std::cout << k.name() << " value: "
				<< k.getString()
				<< std::endl;
	}

	switch (r)
	{
	case 0: archive = new Quotes ("/tmp/quotes.txt");
		break;
	case 1: archive = new Paragraph ("/tmp/paragraph.txt");
		break;
	case 2: archive = new Dhammapada ("/usr/share/doc/display-dhammapada/dhammapada-english-transl.txt");
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
