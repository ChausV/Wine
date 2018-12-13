#include <iostream>

#include "Wine.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << " ------------------- Example ------------------- " << endl;

    cout << "Enter name of wine: ";
    char lab[50] = "";
    cin.getline(lab, 50);
    while (!cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter name of wine: ";
        cin.getline(lab, 50);
    }
    cout << "Enter number of years: ";
    int yrs{0};
    cin >> yrs;
    while (!cin.good())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter number of years: ";
        cin >> yrs;
    }

    Wine holding(lab, yrs);
    holding.getBottles();
    cout << endl;
    holding.show(); // print wine info
    cout << "Total bottles for " << holding.label() << ": " << holding.sum() << endl;
    cout << "---------------" << endl << endl;

    constexpr int kYears = 3;
    int y[kYears] = { 1993, 1995, 1998 };
    int b[kYears] = { 48, 60, 72 };

    Wine more("Chianti", kYears, y, b);
    // Wine more("Chianti", kYears, nullptr, b);
    // Wine more("Chianti", kYears, y, nullptr);
    more.show();
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    cout << endl;

    cout << " ----------------- Additional ---------------- " << endl;
    try {
        Wine hol(NULL, yrs);
    } catch (std::exception & exc) {
        std::cerr << "Exception: " << exc.what() << endl;
    }
    try {
        Wine holl(nullptr, yrs);
    } catch (std::exception & exc) {
        std::cerr << "Exception: " << exc.what() << endl;
    }
    cout << endl;

    Wine noname;
    noname.show();
    cout << "Total bottles for " << noname.label() << ": " << noname.sum() << endl;

    return 0;
}
