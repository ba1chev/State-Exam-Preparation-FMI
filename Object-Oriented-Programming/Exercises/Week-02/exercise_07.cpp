// Създайте структура, която представлява фигурата триъгълник. 
// Реализирайте следните функции:
// Четене от стандартния вход.
// Принтиране на стандартния изход.
// Пресмятане на обиколка.
// Пресмятане на лице.
// Връщне на типа на триъгълника спрямо страните му 
// (равнобедрен, равностранен, разностранен).
#include <iostream>
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

bool areEqual(const float left, const float right) {
    return std::fabs(left - right) < 1e-6f;
}

enum class TriangleType {
    Isosceles, Equilateral, Multifaceted
};

struct Triangle {
public:
    Point p1;
    Point p2;
    Point p3;
    TriangleType type = TriangleType::Multifaceted;

    Triangle(const Point& p1, const Point& p2, const Point& p3) {
        float a = getDistanceBetween(p1, p2);
        float b = getDistanceBetween(p1, p3);
        float c = getDistanceBetween(p3, p2);
        bool pred1 = a + b > c;
        bool pred2 = b + c > a;
        bool pred3 = a + c > b;

        if(!(pred1 && pred2 && pred3)) {
            throw std::runtime_error("Cannot make triangle from this sides");
        }

        if (areEqual(a, b) && areEqual(b, c)) {
            this->type = TriangleType::Equilateral;
        } else if (areEqual(a, b) || areEqual(b, c) || areEqual(a, c)) {
            this->type = TriangleType::Isosceles;
        } else {
            this->type = TriangleType::Multifaceted;
        }

        this->p1 = p1;
        this->p2 = p2;
        this->p3 = p3;
    }
};

Triangle readTriangle(std::istream& is, std::ostream& os) {
    Point p1 = readPoint(is, os);
    Point p2 = readPoint(is, os);
    Point p3 = readPoint(is, os);
    return Triangle(p1, p2, p3);
}

void writeTriangle(const Triangle& triangle, std::ostream& os) {
    writePoint(triangle.p1, os);
    writePoint(triangle.p2, os);
    writePoint(triangle.p3, os);
}

void getTriangleType(const Triangle& triangle, std::ostream& os) {
    switch (triangle.type) {
        case TriangleType::Equilateral: {
            os << "Equilateral";
            break;
        }
        case TriangleType::Isosceles: {
            os << "Isosceles";
            break;
        }
        case TriangleType::Multifaceted: {
            os << "Multifaceted";
            break;
        }
        default: {
            throw std::runtime_error("Invalid input");
        }
    }
}

float getArea(const Triangle& triangle) {
    float a = getDistanceBetween(triangle.p1, triangle.p2);
    float b = getDistanceBetween(triangle.p1, triangle.p3);
    float c = getDistanceBetween(triangle.p2, triangle.p3);

    float semiPerimeter = (a + b + c) * 0.5f;
    float product = semiPerimeter * (semiPerimeter - a) * 
        (semiPerimeter - b) * (semiPerimeter - c);
    return std::sqrt(product);
}

float getPerimeter(const Triangle& triangle) {
    float a = getDistanceBetween(triangle.p1, triangle.p2);
    float b = getDistanceBetween(triangle.p1, triangle.p3);
    float c = getDistanceBetween(triangle.p2, triangle.p3);

    return a + b + c;
}

int main() {
    Triangle triangle = readTriangle(std::cin, std::cout);
    writeTriangle(triangle, std::cout);
    std::cout << "Perimeter: " << getPerimeter(triangle) << std::endl;
    std::cout << "Area: " << getArea(triangle) << std::endl;
    std::cout << "Type: ";
    getTriangleType(triangle, std::cout);
    std::cout << std::endl;

    return 0;
}