#include "WinePr.h"

#include <iostream>

WinePr::WinePr() : std::string("Default")
{}

WinePr::WinePr(const char* l, int y)
	try
	: std::string(l),
	  PairArrayT(std::move(ArrayIntT(y)), std::move(ArrayIntT(y))),
	  ArrayIntT(-1, y)
	{}
	catch (std::logic_error)
	{
		if (l == nullptr)
		{
			std::cerr << "Excepton in Wine constructor:"
			<< " nullptr in first parameter" << std::endl;
		}
	}

WinePr::WinePr(const char* l, int y, const int yr[], const int bot[])
	try
	: std::string(l),
	  PairArrayT(std::move(ArrayIntT(yr, y)), std::move(ArrayIntT(bot, y))),
	  ArrayIntT(-1, y)
	{}
	catch (std::logic_error)
	{
		if (l == nullptr)
		{
			std::cerr << "Excepton in Wine constructor:"
			<< " nullptr in first parameter" << std::endl;
		}
	}

// TODO think about handling case if size of arrays is less than y
WinePr::WinePr(const char* l, int y, const int yr[], const int bot[], const int age[])
	try
	: std::string(l),
	  PairArrayT(std::move(ArrayIntT(yr, y)), std::move(ArrayIntT(bot, y))),
	  ArrayIntT(age, y)
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
	{
		std::cerr << "Out of range. ";
		return false;
	}
	else
		return true;
}
static bool validBottles(int bot)
{
	if (bot < 0 || bot > 10000)
	{
		std::cerr << "Out of range. ";
		return false;
	}
	else
		return true;
}
static bool validAge(int age)
{
	if (age < -1 || age > 120)
	{
		std::cerr << "Out of range. ";
		return false;
	}
	else
		return true;
}

void WinePr::getBottles()
{
	int temp{0};
	const size_t size = PairArrayT::first.size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Enter year: ";
		std::cin >> temp;
		// not the best way. in some cases could cause unfinite loop
	    while (!std::cin.good() || !validYear(temp))
	    {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Try again! Enter year: ";
	        std::cin >> temp;
	    }
		(PairArrayT::first)[i] = temp;

		std::cout << "Enter number of bottles: ";
		std::cin >> temp;
	    while (!std::cin.good() || !validBottles(temp))
	    {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Try again! Enter number of bottles: ";
	        std::cin >> temp;
	    }
		(PairArrayT::second)[i] = temp;
	}
}

void WinePr::getAging()
{
	int temp{0};
	const size_t size = ArrayIntT::size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Enter " << (PairArrayT::first)[i] << "'s barrel age: ";
		std::cin >> temp;
	    while (!std::cin.good() || !validAge(temp))
	    {
	        std::cin.clear();
	        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	        std::cout << "Try again! Enter " << (PairArrayT::first)[i]
	        << "'s wine's barrel age: ";
	        std::cin >> temp;
	    }
		ArrayIntT::operator[](i) = temp;
	}
}

const std::string & WinePr::label() const
{
	return static_cast<const std::string&>(*this);
}

int WinePr::sum() const
{
	if (PairArrayT::second.size() != 0)
		return PairArrayT::second.sum();
	else
		return 0;
}

void WinePr::show() const
{
	std::cout << "Wine \"" << this->label() << "\":" << std::endl;
	const size_t size = PairArrayT::first.size();
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << "Bottling year " << (PairArrayT::first)[i] << " (barrel aging ";
		if (ArrayIntT::operator[](i) == -1)
			std::cout << "unknown";
		else
			std::cout << ArrayIntT::operator[](i) << " months";
		std::cout << ") - ";
		std::cout << (PairArrayT::second)[i] << " boottles";
		std::cout << ((i == size - 1) ? "." : ",") << std::endl;
	}
}
