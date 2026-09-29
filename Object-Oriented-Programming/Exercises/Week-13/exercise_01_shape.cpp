#include "exercise_01_shape.h"

Shape::Shape(const MyVector<Point>& data, ShapeType type) {
    this->data = data;
    this->type = type;
}