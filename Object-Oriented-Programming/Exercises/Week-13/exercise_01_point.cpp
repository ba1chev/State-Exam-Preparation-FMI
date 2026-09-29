#include "exercise_01_point.h"

Point::Point(const float x, const float y) {
    this->x = x;
    this->y = y;
}

float Point::getX() const {
    return this->x;
}

float Point::getY() const {
    return this->y;
}

float Point::getDistance(const Point& left, const Point& right) {
    float newX = right.x - left.x;
    float newY = right.y - left.y;

    return std::sqrt(std::abs(std::pow(newX, 2) + std::pow(newY, 2)));
}

std::ostream& operator << (std::ostream& os, const Point& point) {
    os << "(" << point.getX() << ",";
    os << point.getY() << ")";
    return os;
}