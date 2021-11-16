#include "square.h"

square::square(const point v[]) : rectangle(v) {}

double square::perimeter() const {
    // It's all the same gist
    double side = point::length(pp[1], pp[0]);
    return side * 4;
}

double square::area() const {
    double side = point::length(pp[1], pp[0]);
    return side * side;
}