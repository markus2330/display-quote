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
	string position = "1";
	quotes.push_back("");

	string current;
	while (getline (ifs, current))
	{
		int linepos = current.size()-position.size();
		cout << current << " rfind: " << current.rfind(position)
			<< " size: " << current.size() 
			<< " linepos: " << linepos << endl;
		if (current.size() >= linepos &&
		    current.rfind(position) == linepos &&
		    (current[linepos-1] == ' ' || current[linepos-1] == '.'))
		{
			cout << position << " found" << endl;
			++posnr;
			std::ostringstream str;
			str << posnr;
			position = str.str();
			cout << "now search for : " << position
				<< " nr: " << posnr
				<< " str: " << str.str() << endl;
			if (!quotes.back().empty()) quotes.back() += "\n";
			quotes.back() += current;
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
