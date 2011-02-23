#include <iostream>
#include <collection.hpp>

#include <kdb>

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		Collection c;
		// c.getRandomQuote (std::cout);
		// std::cout << std::endl;
	}
	else if (argc == 2)
	{
		Collection c (argv[1]);
	}
	else if (argc == 5)
	{
		kdb::KDB kdb;

		kdb::Key root("user/sw/dfc", KEY_END);
		root += argv[1];

		kdb::KeySet config;
		kdb.get (config, root);
		config.rewind();
		kdb::Key k;
		while (k = config.next())
		{
			std::cout << k.name() << " value: "
				<< k.getString()
				<< std::endl;
		}

		if (!config.lookup(root))
		{
			std::cout << "Create new profile" << std::endl;
			root.setString ("Root key of profile");
			config.append(root);
		}

		kdb::Key archive (root.dup());
		archive += argv[2];
		archive.setString ("Root key of archive");
		config.append (archive);

		kdb::Key path (archive.dup());
		path += "path";
		path.setString(argv[3]);
		config.append (path);

		kdb::Key type (archive.dup());
		type += "type";
		type.setString(argv[4]);
		config.append (type);
		kdb.set (config, root);
		std::cout << "Add new archive below " << archive.name() << std::endl;
	}
}
