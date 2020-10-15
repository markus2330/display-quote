#include <iostream>
#include <memory>

#include <collection.hpp>
#include <factory.hpp>

#include <cstdlib>
#include <ctime>

#include <iostream>

#ifndef NO_GETPID
#include <unistd.h>
#endif

#include <kdb.hpp>

kdb::Key removeNamespace (kdb::Key k)
{
	kdb::Key key = k.dup();
	std::string name = key.getName ();
	size_t pos = name.find_first_of ('/');
	if (pos == std::string::npos)
	{
		// we directly had a namespace
		key.setName ("/");
	}
	else
	{
		name = name.substr (pos);
		key.setName (name);
	}
	return key;
}


Collection::Collection(std::string profile)
{
	srand (time(0)
#ifndef NO_GETPID
	       + getpid()
#endif
			);

	kdb::KDB kdb;

	if (profile.empty()) profile = "current";

	kdb::Key root("/sw/elektra/dq/#0/" + profile + "/", KEY_END);

	kdb::KeySet config;
	kdb.get(config, root);

	Factory f;

	config.rewind();
	kdb::Key key;
	while (key = config.next())
	{
		kdb::Key k = removeNamespace(key);
		if (k.isDirectBelow(root))
		{
			kdb::Key path =
				config.lookup (k.getName() + "/path");
			if (!path) throw std::runtime_error("Archive without path found below " + k.getName());

			kdb::Key type =
				config.lookup (k.getName() + "/type");
			if (!type) throw std::runtime_error("Archive without type found below " + k.getName());

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
		os << "dq error: No archive found";
		return;
	}

	int a = random(archives.size());

	if (archives[a]->size() == 0)
	{
		os << "dq error: No quote in archive found";
		return;
	}

	int r = random(archives[a]->size());

	os << archives[a]->operator[](r);
}
