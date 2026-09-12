// Създайте структура, която представлява точка в двумерното пространство. 
// Реализирайте следните функции:
// Четене от стандартния вход.
// Принтиране на стандартния изход.
// Разстояние между две точки.
#include <iostream>
#include <fstream>
#include <cmath>

struct Point {
public:
    float x = 0.0f;
    float y = 0.0f;
};

Point readPoint(std::istream& is, std::ostream& os) {
    Point point;
    os << "Enter x: ";
    is >> point.x;
    os << "Enter y: ";
    is >> point.y;

    return point;
}

void writePoint(const Point& point, std::ostream& os) {
    os << point.x << " ";
    os << point.y << std::endl;
}

float getDistanceBetween(const Point& p1, const Point& p2) {
    float first = p1.x - p2.x;
    float second = p1.y - p2.y;
    return sqrt(first * first + second * second);
}

int main() {
    Point point1 = readPoint(std::cin, std::cout);
    Point point2 = readPoint(std::cin, std::cout);
    writePoint(point1, std::cout);
    std::cout << getDistanceBetween(point1, point2) << std::endl;
    return 0;
}