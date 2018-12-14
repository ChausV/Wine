#include <iostream>

#include "Wine.h"
#include "WinePr.h"

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cout << " ================================================== " << endl;
    cout << " ============ Wine class (composition) ============ " << endl;
    cout << " ================================================== " << endl;

    cout << " ---------------- Example based ---------------- " << endl;
{
    cout << "Enter name of wine: ";
    char lab[50] = "";
    cin.getline(lab, 50);
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter name of wine: ";
        cin.getline(lab, 50);
    }
    cout << "Enter number of years: ";
    int yrs{0};
    cin >> yrs;
    while (!cin.good() || yrs < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter number of years: ";
        cin >> yrs;
    }

    Wine holding(lab, yrs);
    holding.getBottles();
    cout << endl;
    holding.show();
    cout << "Total bottles for " << holding.label() << ": " << holding.sum() << endl;
    cout << "---------------" << endl << endl;

    holding.getAging();
    holding.show();
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

    cout << " ------------------ Additional ----------------- " << endl;
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
    cout << "---------------" << endl << endl;

    int a[kYears] = { 6, 12, 18 };
    Wine riesling("Riesling", kYears, y, b, a);
    riesling.show();
    cout << "Total bottles for " << riesling.label() << ": " << riesling.sum() << endl;
    cout << "---------------" << endl << endl;

    Wine noname;
    noname.show();
    // TODO add changeName() and resize() member-functions to
    // justify default constructor usage
    cout << "Total bottles for " << noname.label() << ": " << noname.sum() << endl;

    cout << "---------------" << endl;
}
    cout << " ================================================== " << endl;
    cout << " ======== Wine class (private inheritance) ======== " << endl;
    cout << " ================================================== " << endl;
{
    cout << " ---------------- Example based ---------------- " << endl;

    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter name of wine: ";
    char lab[50] = "";
    cin.getline(lab, 50);
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter name of wine: ";
        cin.getline(lab, 50);
    }
    cout << "Enter number of years: ";
    int yrs{0};
    cin >> yrs;
    while (!cin.good() || yrs < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Try again! Enter number of years: ";
        cin >> yrs;
    }

    WinePr holding(lab, yrs);
    holding.getBottles();
    cout << endl;
    holding.show();
    cout << "Total bottles for " << holding.label() << ": " << holding.sum() << endl;
    cout << "---------------" << endl << endl;

    holding.getAging();
    holding.show();
    cout << "Total bottles for " << holding.label() << ": " << holding.sum() << endl;
    cout << "---------------" << endl << endl;


    constexpr int kYears = 3;
    int y[kYears] = { 1999, 2003, 2008 };
    int b[kYears] = { 42, 24, 34 };

    WinePr more("Merlot", kYears, y, b);
    // // Wine more("Merlot", kYears, nullptr, b);
    // // Wine more("Merlot", kYears, y, nullptr);
    more.show();
    cout << "Total bottles for " << more.label() << ": " << more.sum() << endl;
    cout << endl;

    cout << " ------------------ Additional ----------------- " << endl;
    try {
        WinePr hol(NULL, yrs);
    } catch (std::exception & exc) {
        std::cerr << "Exception: " << exc.what() << endl;
    }
    try {
        WinePr holl(nullptr, yrs);
    } catch (std::exception & exc) {
        std::cerr << "Exception: " << exc.what() << endl;
    }
    cout << "---------------" << endl << endl;

    int a[kYears] = { 6, 12, 18 };
    WinePr riesling("Riesling", kYears, y, b, a);
    riesling.show();
    cout << "Total bottles for " << riesling.label() << ": " << riesling.sum() << endl;
    cout << "---------------" << endl << endl;

    WinePr noname;
    noname.show();
    // TODO add changeName() and resize() member-functions to
    // justify default constructor usage
    cout << "Total bottles for " << noname.label() << ": " << noname.sum() << endl;

    cout << "---------------" << endl;
}
    return 0;
}
