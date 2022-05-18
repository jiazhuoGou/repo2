#include "../include/Circle.h"
#include<iostream>

using namespace std;

Circle::Circle(double radius, Color color_, bool filled_)
: Shape{color_, filled_}
{
	this->radius_ = radius;

}

Circle::Circle()
{
	radius_ = 1;
}

double Circle::getArea()
{
	return (3.14 * this->radius_ * this->radius_);
}

void Circle::setRadius(double radius)
{
	this->radius_ = radius;
}

double Circle::getRadisu()
{
	return this->radius_;
}

void Circle::print(Circle &c)
{
	cout << "用引用传值：" <<  c.getArea() << endl;
}

void Circle::print(Circle *c)
{
	cout << "用指针传值："  << c->getArea() << endl;
}

string Circle::toString()
{
	return ( "circle: radius " + std::to_string(radius_) + ", "
	+ colorToString() + " " + filledToString() );
	
}