#include <wiki.hpp>
#include <fstream>

using namespace std;

Wiki::Wiki(std::string filename)
{
	ifstream fin(filename.c_str());

	string line;
	string quote;
	while (getline (fin, line))
	{
		if (line[0] == '=')
		{
			if (quote.empty()) continue;
			quotes.push_back(quote);
			quote.clear();
		}

		if (!quote.empty()) quote += "\n";
		quote += line;
	}
	if (!quote.empty()) quotes.push_back(quote);
}

Wiki::~Wiki()
{}

const std::string& Wiki::operator [] (int index) const
{
	return quotes[index];
}

int Wiki::size() const
{
	return quotes.size();
}
