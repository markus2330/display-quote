#include <lines.hpp>
#include <fstream>

using namespace std;

Lines::Lines(std::string filename)
{
	ifstream fin(filename.c_str());

	string line;
	while (getline (fin, line))
	{
		if (!line.empty()) quotes.push_back(line);
	}
}

Lines::~Lines()
{}

const std::string& Lines::operator [] (int index) const
{
	return quotes[index];
}

int Lines::size() const
{
	return quotes.size();
}
