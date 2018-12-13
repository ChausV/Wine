#ifndef WINE_H
#define WINE_H

#include <string>
#include <utility>
#include <valarray>
#include <vector>

class Wine
{
public:
	Wine();
	Wine(const char* l, int y);
	Wine(const char* l, int y, const int yr[], const int bot[]);

	void getBottles();
	const std::string & label() const;
	int sum() const;
	void show() const;

private:
	using ArrayIntT = std::valarray<int>;
	using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
	using VectorIntT = std::vector<int>;

	std::string name;
	PairArrayT quantity;
	VectorIntT age;
};

#endif // WINE_H
