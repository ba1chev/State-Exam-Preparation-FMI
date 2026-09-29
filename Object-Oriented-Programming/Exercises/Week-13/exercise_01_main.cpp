// Създайте абстрактен клас Shape за геометрични фигури с методи за изчисляване на площ,
// периметър и проверка дали точка принадлежи на фигурата. Реализирайте наследниците Triangle,
// Rectangle и Circle, които дефинират тези методи за съответните фигури.
#include <iostream>
#include "exercise_01_triangle.h"
#include "exercise_01_rectangle.h"
#include "exercise_01_circle.h"

void printShape(const Shape& shape, const Point& point) {
    std::cout << "Area: " << shape.calculateArea() << std::endl;
    std::cout << "Perimeter: " << shape.calculatePerimeter() << std::endl;
    std::cout << "Contains " << point << ": " <<
        (shape.contains(point) ? "yes" : "no") << std::endl;
}

int main() {
    MyVector<Point> triangleData;
    triangleData.pushBack(Point(0, 0));
    triangleData.pushBack(Point(4, 0));
    triangleData.pushBack(Point(0, 3));
    Triangle triangle(triangleData);
    std::cout << "===== Triangle =====" << std::endl;
    printShape(triangle, Point(1, 1));

    MyVector<Point> rectangleData;
    rectangleData.pushBack(Point(0, 0));
    rectangleData.pushBack(Point(4, 2));
    Rectangle rectangle(rectangleData);
    std::cout << "===== Rectangle =====" << std::endl;
    printShape(rectangle, Point(5, 1));

    MyVector<Point> circleData;
    circleData.pushBack(Point(0, 0));
    circleData.pushBack(Point(3, 0));
    Circle circle(circleData);
    std::cout << "===== Circle =====" << std::endl;
    printShape(circle, Point(1, 1));

    return 0;
}