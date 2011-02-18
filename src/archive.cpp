#include <archive.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

Archive::Archive(std::string filename)
{
	ifstream ifs (filename.c_str());
	int posnr = 1;
	quotes.push_back("");

	string current;

	while (getline (ifs, current))
	{
		vector<int> markers;

		string::reverse_iterator it = current.rbegin();
		for(; it != current.rend();)
		{
			int number = 0;
			int decpos = 1;
			bool found = false;
			while (*it >= '0' && *it <='9')
			{
				// we found a paragraph notation
				number += (*it-'0')*decpos;
				decpos *= 10;
				++it;
			}
			while (*it == ',' || *it == ' ')
			{
				// skip in between
				++it;
			}
			if (!number) break;
			markers.push_back (number);
		}
		current.erase(it.base(), current.end());

		if (!markers.empty())
		{
			if (!quotes.back().empty()) quotes.back() += "\n";
			quotes.back() += current;
			markers.pop_back();

			std::string copy = quotes.back();
			while (!markers.empty())
			{
				markers.pop_back();
				quotes.push_back(copy);
			}
			quotes.push_back(""); // start a new quote
		}
		else if (current == "")
		{
			// found new paragraph, make this quote empty
			quotes.back() = "";
		}
		else
		{
			// append to quote..
			if (!quotes.back().empty()) quotes.back() += "\n";
			quotes.back() += current;
		}
	}
	quotes.pop_back(); // undo last useless push_back operation
}

Archive::~Archive()
{}

const std::string& Archive::operator [] (int index) const
{
	return quotes[index];
}

int Archive::size() const
{
	return quotes.size();
}
