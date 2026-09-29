#include "exercise_01_circle.h"

Circle::Circle(const MyVector<Point>& data):
    Shape(data, ShapeType::Circle) {
    if (data.getSize() != 2) {
        throw std::runtime_error("Invalid data input");
    }
}

float Circle::calculateArea() const {
    float radius = Point::getDistance(this->data[0], this->data[1]);
    return 3.14f * std::pow(radius, 2);
}

float Circle::calculatePerimeter() const {
    float radius = Point::getDistance(this->data[0], this->data[1]);
    return 2 * 3.14f * radius;
}

bool Circle::contains(const Point& point) const {
    float radius = Point::getDistance(this->data[0], this->data[1]);
    return Point::getDistance(this->data[0], point) <= radius;
}