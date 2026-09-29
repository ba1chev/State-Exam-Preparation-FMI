#pragma once
#include "exercise_01_point.h"
#include "exercise_01_my_vector.hpp"

enum class ShapeType {
    Triangle, Rectangle, Circle, None
};

class Shape {
protected:
    MyVector<Point> data;
    ShapeType type = ShapeType::None;

public:
    Shape(const MyVector<Point>& data, ShapeType type);

    virtual float calculateArea() const = 0;
    virtual float calculatePerimeter() const = 0;
    virtual bool contains(const Point& point) const = 0;
    virtual ~Shape() = default;
};