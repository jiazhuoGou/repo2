# pragma once

#include <iostream>
#include <string>
#include <array>

using namespace std::string_literals;

using std::string;

enum class Color
{
    white, black, red, green, blue, yellow, 
};

class Shape
{
private:
    Color color {Color::black};
    bool filled{false};
    std::array<string, 6> colorNames{"white", "black", "red", "green", "blue", "yellow"};
public:
    Shape() = default;
    Shape(Color color_, bool filled_);

    Color getColor();
    void setColor(Color color_);
    bool isFilled();
    void setFilled(bool Filled_);
    virtual string toString();
    string filledToString();
    string colorToString();

    virtual double getArea() = 0;
    
    ~Shape();
};

