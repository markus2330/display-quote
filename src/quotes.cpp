#include <quotes.hpp>

#include <fstream>

using namespace std;

Quotes::Quotes (std::string file)
{
	ifstream fin (file.c_str());
	string line;
	string quote;
	while (getline (fin, line))
	{
		if (line == "")
		{
			// skip empty lines
		}
		else if (line == "~")
		{
			quotes.push_back(quote);
			quote.clear();
		}
		else
		{
			if (!quote.empty()) quote += "\n";
			quote += line;
		}
	}
}

Quotes::~Quotes ()
{}

const std::string& Quotes::operator [] (int index) const
{
	return quotes[index];
}

int Quotes::size() const
{
	return quotes.size();
}
