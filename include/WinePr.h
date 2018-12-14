#ifndef WINE_PR_H
#define WINE_PR_H

#include <string>
#include <utility>
#include <valarray>
#include <vector>

class WinePr : private std::string,
			private std::pair<std::valarray<int>, std::valarray<int>>,
			private std::valarray<int>
{
public:
	WinePr();
	WinePr(const char* l, int y);
	WinePr(const char* l, int y, const int yr[], const int bot[]);
	WinePr(const char* l, int y, const int yr[], const int bot[], const int age[]);

	void getBottles();
	void getAging();
	const std::string & label() const;
	int sum() const;
	void show() const;

private:
	using ArrayIntT = std::valarray<int>;
	using PairArrayT = std::pair<ArrayIntT, ArrayIntT>;
};

#endif // WINE_PR_H
