#include <task.hpp>
#include <fstream>

using namespace std;

Task::Task(std::string filename)
{
	ifstream fin(filename.c_str());

	string line;
	while (getline (fin, line))
	{
		if (!line.empty() && line[0] != '#') quotes.push_back(line);
	}
}

Task::~Task()
{}

const std::string& Task::operator [] (int index) const
{
	return quotes[index];
}

int Task::size() const
{
	return quotes.size();
}
