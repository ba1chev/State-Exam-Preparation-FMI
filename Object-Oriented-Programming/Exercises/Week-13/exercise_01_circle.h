#pragma once
#include "exercise_01_shape.h"

class Circle: public Shape {
public:
    Circle(const MyVector<Point>& data);

    float calculateArea() const override;
    float calculatePerimeter() const override;
    bool contains(const Point& point) const override;
};