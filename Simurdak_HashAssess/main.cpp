#include "hash.h"
#include "tHashmap.h"

int main()
{
	tHashmap<std::string, int> favoriteNumbersByName;
	favoriteNumbersByName["Terry"] = 5;

	std::cout << favoriteNumbersByName["Terry"] << std::endl;

	while(true){}

	return 0;
}