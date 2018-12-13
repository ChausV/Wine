#include "Wine.h"

#include <iostream>

Wine::Wine() : name("Default")
{}

Wine::Wine(const char* l, int y)
	try
	: name(l), quantity(std::move(ArrayIntT(y)), std::move(ArrayIntT(y)))
	{}
	catch (std::logic_error)
	{
		if (l == nullptr)
		{
			std::cerr << "Excepton in Wine constructor:"
			<< " nullptr in first parameter" << std::endl;
		}
	}

Wine::Wine(const char* l, int y, const int yr[], const int bot[])
	try
	: name(l), quantity(std::move(ArrayIntT(yr, y)), std::move(ArrayIntT(bot, y)))
	{}
	catch (std::logic_error)
	{
		if (l == nullptr)
		{
			std::cerr << "Excepton in Wine constructor:"
			<< " nullptr in first parameter" << std::endl;
		}
	}

// validation for getBottles()
static bool validYear(int year)
{
	if (year < 1000 || year > 3000)
		return false;
	else
		return true;
}
static bool validBottles(int bot)
{
	if (bot < 0 || bot > 10000)
		return false;
	else
		return true;
}

void Wine::getBottles()
{
	int temp{0};
	const size_t size = quantity.first.size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Enter year: ";
		std::cin >> temp;
	    while (!std::cin.good() || !validYear(temp))
	    {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Try again! Enter year: ";
	        std::cin >> temp;
	    }
		(quantity.first)[i] = temp;
		std::cout << "Enter number of bottles: ";
		std::cin >> temp;
	    while (!std::cin.good() || !validBottles(temp))
	    {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Try again! Enter number of bottles: ";
	        std::cin >> temp;
	    }
		(quantity.second)[i] = temp;
	}
}

const std::string & Wine::label() const
{
	return name;
}

int Wine::sum() const
{
	if (quantity.second.size() != 0)
		return quantity.second.sum();
	else
		return 0;
}

void Wine::show() const
{
	std::cout << "Wine \"" << name << "\":" << std::endl;
	const size_t size = quantity.first.size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Year " << (quantity.first)[i] << " - ";
		std::cout << (quantity.second)[i] << " boottles";
		std::cout << ((i == size - 1) ? "." : ",") << std::endl;
	}
}
