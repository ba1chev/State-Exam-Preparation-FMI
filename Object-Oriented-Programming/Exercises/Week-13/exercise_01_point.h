#pragma once
#include <iostream>
#include <cmath>

class Point {
private:
    float x = 0.0f;
    float y = 0.0f;

public:
    Point() = default;
    Point(const float x, const float y);

    float getX() const;
    float getY() const;
    static float getDistance(const Point& left, const Point& right);

    friend std::ostream& operator << (std::ostream& os, const Point& point);
};