#include"../include/Employee.h"
#include"../include/Date.h"

using namespace std;


Employee::Employee()
:Employee("Alan", Gender::male, Date(2000, 4, 1))
{}

Employee::Employee(std::string name, Gender gender, Date birthday)
:name{name}, gender{gender}
{
    Employee::numberOfObjects++;
    this->birthday = new Date{birthday};
    cout << "Now there are : " << numberOfObjects << " employees" << endl;
}

Employee::Employee(const Employee &e)
{
    this->birthday = new Date{*(e.birthday)};
    this->name = e.name;
    this->gender = e.gender;
    numberOfObjects++;
}


    
void Employee::setName(std::string name)
{
    this->name = name;
}

std::string Employee::getName()
{
    return this->name;
}

void Employee::setGender(Gender gender)
{
    this->gender = gender;
}

Gender Employee::getGender()
{
    return this->gender;
}

void Employee::setBirthday(Date birthday)
{
    *(this->birthday) = birthday;
}

Date* Employee::getBirthday()
{
    return birthday;
}

Employee::~Employee()
{
    Employee::numberOfObjects--;
    cout << "delete an " << this->name << " employee ," << "Now there are : " << numberOfObjects << " employees" << endl;
    delete this->birthday;
}

std::string Employee::toString()
{
    return (name + " " +  (gender == Gender::male?std::string("male"):std::string("female"))
        + " " + this->birthday->toString());
}