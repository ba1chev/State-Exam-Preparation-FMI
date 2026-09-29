#include "exercise_01_rectangle.h"
#include <algorithm>

Rectangle::Rectangle(const MyVector<Point>& data):
    Shape(data, ShapeType::Rectangle) {
    if (data.getSize() != 2) {
        throw std::runtime_error("Invalid data input");
    }
}

float Rectangle::calculateArea() const {
    float width = std::abs(this->data[1].getX() - this->data[0].getX());
    float height = std::abs(this->data[1].getY() - this->data[0].getY());
    return width * height;
}

float Rectangle::calculatePerimeter() const {
    float width = std::abs(this->data[1].getX() - this->data[0].getX());
    float height = std::abs(this->data[1].getY() - this->data[0].getY());
    return 2 * (width + height);
}

bool Rectangle::contains(const Point& point) const {
    float minX = std::min(this->data[0].getX(), this->data[1].getX());
    float maxX = std::max(this->data[0].getX(), this->data[1].getX());
    float minY = std::min(this->data[0].getY(), this->data[1].getY());
    float maxY = std::max(this->data[0].getY(), this->data[1].getY());

    return point.getX() >= minX && point.getX() <= maxX &&
        point.getY() >= minY && point.getY() <= maxY;
}
