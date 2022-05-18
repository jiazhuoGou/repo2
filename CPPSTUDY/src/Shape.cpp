#include "../include/Shape.h"
#include<array>

using namespace std::string_literals;

Shape::Shape(Color color_, bool filled_)
{
    this->color = color_;
    this->filled = filled_;
}

Color Shape::getColor()
{
    return this->color;
}

void Shape::setColor(Color color_)
{
    this->color = color_;
}

bool Shape::isFilled()
{
    return filled;
}

void Shape::setFilled(bool Filled_)
{
    filled = Filled_;
}

string Shape::toString()
{
    return "Shape : " + colorToString() + " " + filledToString();
}

string Shape::colorToString()
{
    return colorNames[static_cast<int>(color)];
}

string Shape::filledToString()
{
    return (filled?"filled"s:"not filled");
}


Shape::~Shape()
{
}