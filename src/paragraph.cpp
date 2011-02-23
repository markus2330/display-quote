#include <paragraph.hpp>
#include <fstream>

using namespace std;

Paragraph::Paragraph(std::string filename)
{
	ifstream fin(filename.c_str());

	string line;
	string quote;
	while (getline (fin, line))
	{
		if (line.empty())
		{
			if (!quote.empty()) quotes.push_back (quote);
			quote.clear();
		}
		else
		{
			if (!quote.empty()) quote += "\n";
			quote += line;
		}
	}
}

Paragraph::~Paragraph()
{}

const std::string& Paragraph::operator [] (int index) const
{
	return quotes[index];
}

int Paragraph::size() const
{
	return quotes.size();
}
