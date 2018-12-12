#ifndef WINE_H
#define WINE_H

#include <string>
#include <utility>

class Wine
{
public:

private:
	using ArrayIntT = std::valarray<int>;
	using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;

	// std::string name;
	// std::pair<std::valarray<int>, std::valarray<int>> year_number;
	// std::valarray<int> age;
	std::string name;
	PairArrayT year_number;
	ArrayIntT age;
};

#endif // WINE_H
