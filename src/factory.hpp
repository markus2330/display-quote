#ifndef FACTORY_HPP
#define FACTORY_HPP

#include <map>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

#include <archive.hpp>

//TODO: to add a new archive, 1.) include your header here
#include <quotes.hpp>
#include <paragraph.hpp>
#include <dhammapada.hpp>
#include <lines.hpp>
#include <wiki.hpp>
#include <task.hpp>

class Instancer
{
public:
	virtual Archive* get(std::string path) = 0;
	virtual ~Instancer() {}
};

template <class T>
class Cnstancer: public Instancer
{
	virtual T* get(std::string path)
	{
		return new T(path);
	}
};

class Factory
{
	std::map<std::string, Instancer*> m_factory;
public:
	Factory() :
		m_factory()
	{
		m_factory.insert(std::make_pair("dhammapada", new Cnstancer<Dhammapada>()));
		m_factory.insert(std::make_pair("paragraph", new Cnstancer<Paragraph>()));
		m_factory.insert(std::make_pair("quotes", new Cnstancer<Quotes>()));
		m_factory.insert(std::make_pair("lines", new Cnstancer<Lines>()));
		m_factory.insert(std::make_pair("wiki", new Cnstancer<Wiki>()));
		m_factory.insert(std::make_pair("task", new Cnstancer<Task>()));
		// TODO: to add a new archive, 2.) add a line here
		// TODO: 3.) add the sources to src/CMakeLists.txt-> and you are done
	}

	~Factory()
	{
		for (
			std::map<std::string,Instancer*>::iterator it =
			m_factory.begin();
			it != m_factory.end();
			it++)
		{
			delete it->second;
		}
	}

	/**Returns a list of available Archives */
	std::vector<std::string> getArchiveFormats()
	{
		std::vector<std::string> ret;
		for (
			std::map<std::string,Instancer*>::iterator it =
			m_factory.begin();
			it != m_factory.end();
			it++)
		{
			ret.push_back(it->first);
		}
		return ret;
	}

	std::auto_ptr<Archive> get(std::string const& which,
			std::string const& path)
	{
		Instancer* instancer = m_factory[which];
		if (instancer)
		{
			std::auto_ptr <Archive> ret(instancer->get(path));
			return ret;
		}
		else
		{
			m_factory.erase(which);
			throw std::runtime_error("Unknown archive type " + which);
		}

	}
};



#endif
