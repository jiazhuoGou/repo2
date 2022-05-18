#include<iostream>
#include<string>
#include "Date.h"

enum class Gender
{
    male,
    famale,
};

class Employee
{
private:
    std::string name;
    Gender  gender;
    Date    *birthday;
    static int numberOfObjects;
public:
    Employee();
    Employee(const Employee &e);
    Employee(std::string name, Gender gender, Date birthday);
    void setName(std::string name);
    std::string getName();
    void setGender(Gender gender);
    Gender getGender();
    void setBirthday(Date birthday);
    Date* getBirthday();
    std::string toString();

    ~Employee();
    
};


