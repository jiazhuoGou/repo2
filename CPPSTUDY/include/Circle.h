# pragma once

#include"./Shape.h"

class Circle : public Shape
{
private:
	double radius_;
public:	
	Circle(double radius, Color color_, bool filled_);
	Circle();
	void setRadius(double radius);
	double getRadisu();
	double getArea() override;
	//void print(Circle c);
	void print(Circle &c);
	void print(Circle *c);
	string toString() override;

};