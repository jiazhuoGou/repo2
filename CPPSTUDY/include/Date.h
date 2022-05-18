#pragma once

#include<iostream>
#include<string>

class Date
{
private:
    /* data */
    int year{2019}, month{1}, day{1};
public:
    Date() = default;
    Date(int y, int m, int d);
    int getYear();
    void setYear(int y);
    int getMonth();
    void setMonth(int m);
    int getDay();
    void setDay(int d);
    std::string toString();

};
