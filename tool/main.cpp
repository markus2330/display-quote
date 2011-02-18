#include <iostream>
#include <archive.hpp>

#include <stdlib.h>
#include <time.h>

int main()
{
	Archive a("/usr/share/doc/display-dhammapada/dhammapada-english-transl.txt");

	srand (time(0));
	int r = 1+(int) ((double)a.size()*rand()/(RAND_MAX+1.0));

	std::cout << a[r] << std::endl;
}
