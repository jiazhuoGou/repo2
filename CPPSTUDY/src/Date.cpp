#include"../include/Date.h"

using namespace std;


Date::Date(int y, int m, int d): year{y}, month{m}, day{d}
{
    cout << "Date: " << toString() << endl;
}

int Date::getYear()
{
    return year;
}

void Date::setYear(int y)
{
    year = y;
}
    
int Date::getMonth()
{
    return month;
}
    
void Date::setMonth(int m)
{
    month = m;
}

int Date::getDay()
{
    return day;
}
    
void Date::setDay(int d)
{
    day = d;
}

std::string Date::toString()
{
    return (to_string(year) + "-" + to_string(month) + "-" +to_string(day));
}