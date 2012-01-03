#ifndef TASK_H
#define TASK_H

#include <archive.hpp>
#include <string>
#include <vector>

/**Task for any quote reader.
  **/
class Task: public Archive
{
public:
	Task (std::string file);
	~Task ();
	const std::string& operator [] (int index) const;
	int size() const;

private:
	/**the underlying information
	  *to access */
	std::vector<std::string> quotes;
};

#endif
