#include <iostream>
#include <memory>

#include <collection.hpp>
#include <factory.hpp>

#include <cstdlib>
#include <ctime>

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

	Factory f;

	config.rewind();
	std::cout << "size of config: " << config.size() << std::endl;
	kdb::Key k;
	while (k = config.next())
	{
		if (root.isDirectBelow(k))
		{
			kdb::Key path =
				config.lookup (k.getName() + "/path");
			if (!path) throw ("Archive without path found");

			kdb::Key type =
				config.lookup (k.getName() + "/type");
			if (!type) throw ("Archive without type found");

			std::auto_ptr<Archive> a =
				f.get(type.getString(),
				path.getString());
			archives.push_back(a.release());
			std::cout << "Create archive:"
				<< " type: " << type.getString()
				<< " path: " << path.getString()
				<< std::endl;
		}
	}
}

Collection::~Collection()
{
	for (
		std::vector<Archive*>::iterator it =
		archives.begin();
		it != archives.end();
		it++)
	{
		delete *it;
	}
}

/*Random number between 0 and number*/
int random(int number)
{
	return ((double)number)*rand()/RAND_MAX;
}

void Collection::getRandomQuote(std::ostream &os)
{
	int a = random(archives.size());

	int r = random(archives[a]->size());

	os << archives[a]->operator[](r);
}
