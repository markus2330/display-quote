#include <iostream>
#include <memory>

#include <collection.hpp>
#include <factory.hpp>

#include <cstdlib>
#include <ctime>

#ifdef NO_GETPID
#include <unistd.h>
#endif

#include <kdb>

Collection::Collection(std::string profile)
{
	srand (time(0)
#ifdef NO_GETPID
	       + getpid()
#endif
			);

	kdb::KDB kdb;

	kdb::Key userroot("user/sw/dfc", KEY_END);
	userroot += profile;

	kdb::Key sysroot("system/sw/dfc", KEY_END);
	sysroot += profile;

	kdb::KeySet config;
	kdb.get(config, userroot);
	kdb.get(config, sysroot);

	Factory f;

	config.rewind();
	kdb::Key k;
	while (k = config.next())
	{
		if (userroot.isDirectBelow(k))
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
		}
		else if (sysroot.isDirectBelow(k))
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
	if (archives.size() == 0)
	{
		os << "dfc error: No archive found";
		return;
	}

	int a = random(archives.size());

	if (archives[a]->size() == 0)
	{
		os << "dfc error: No quote in archive found";
		return;
	}

	int r = random(archives[a]->size());

	os << archives[a]->operator[](r);
}
