#pragma once

#include "./Shape.h"

class Rectangle : public Shape
{
private:
    double width{1.0};
    double height{1.0};
public:
    Rectangle() = default;
    Rectangle(double width_, double height_, Color color_, bool filled_);

    double  getWidth() const;
    void    setWidth(double width_);
    double  getHeight() const;
    void    setHeight(double height_);
    double  getArea() override;    
    string  toString() override;

    ~Rectangle();
};

