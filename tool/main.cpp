#include <iostream>
#include <collection.hpp>

#include <kdb.hpp>

int main(int argc, char** argv) try
{
	if (argc == 1)
	{
		Collection c;
		c.getRandomQuote (std::cout);
		std::cout << std::endl;
	}
	else if (argc == 2)
	{
		Collection c (argv[1]);
		c.getRandomQuote (std::cout);
		std::cout << std::endl;
	}
	else if (argc == 5)
	{
		kdb::KDB kdb;

		kdb::Key root(std::string("user/sw/elektra/dq/#0/") + argv[1], KEY_END);

		kdb::KeySet config;
		kdb.get (config, root);

		if (!config.lookup(root))
		{
			std::cout << "Create new profile" << std::endl;
			root.setString ("Root key of profile");
			config.append(root);
		}

		kdb::Key archive (root.dup());
		archive.addBaseName(argv[2]);
		archive.setString ("Root key of archive");
		config.append (archive);

		kdb::Key path (archive.dup());
		path.addBaseName("path");
		path.setString(argv[3]);
		config.append (path);

		kdb::Key type (archive.dup());
		type.addBaseName("type");
		type.setString(argv[4]);
		config.append (type);
		kdb.set (config, root);
		std::cout << "Add new archive below " << archive.getName() << std::endl;
	}
}
catch (std::exception const & e)
{
	std::cerr << e.what() << std::endl;
}

