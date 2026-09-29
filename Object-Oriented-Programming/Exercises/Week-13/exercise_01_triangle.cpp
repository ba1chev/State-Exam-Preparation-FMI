#include "exercise_01_triangle.h"

Triangle::Triangle(const MyVector<Point>& data):
    Shape(data, ShapeType::Triangle) {
    if (data.getSize() != 3) {
        throw std::runtime_error("Invalid data input");
    }
}
    
float Triangle::calculateArea() const {
    float side1 = Point::getDistance(this->data[0], this->data[1]);
    float side2 = Point::getDistance(this->data[1], this->data[2]);
    float side3 = Point::getDistance(this->data[0], this->data[2]);
    float semiPerimeter = 0.5f * (side1 + side2 + side3);
    return std::sqrt(semiPerimeter * (semiPerimeter - side1) *
        (semiPerimeter - side2) * (semiPerimeter - side3));
}

float Triangle::calculatePerimeter() const {
    float side1 = Point::getDistance(this->data[0], this->data[1]);
    float side2 = Point::getDistance(this->data[1], this->data[2]);
    float side3 = Point::getDistance(this->data[0], this->data[2]);
    return side1 + side2 + side3;
}

bool Triangle::contains(const Point& point) const {
    MyVector<Point> first;
    first.pushBack(point);
    first.pushBack(this->data[0]);
    first.pushBack(this->data[1]);

    MyVector<Point> second;
    second.pushBack(point);
    second.pushBack(this->data[1]);
    second.pushBack(this->data[2]);

    MyVector<Point> third;
    third.pushBack(point);
    third.pushBack(this->data[0]);
    third.pushBack(this->data[2]);

    float sum = Triangle(first).calculateArea() +
        Triangle(second).calculateArea() + Triangle(third).calculateArea();
    return std::abs(sum - this->calculateArea()) < 0.0001f;
}