#include <template.hpp>
#include <fstream>

using namespace std;

Template::Template(std::string filename)
{
	ifstream fin(filename.c_str());

	string line;
	string quote;
	while (getline (fin, line))
	{
	}
}

Template::~Template()
{}

const std::string& Template::operator [] (int index) const
{
	return quotes[index];
}

int Template::size() const
{
	return quotes.size();
}
