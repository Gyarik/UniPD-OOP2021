#include "rect.h"

rectangle::rectangle(const point v[]) : polygon(4, v) {}

double rectangle::perimeter() const {
    // Math
    double base = point::length(pp[1], pp[0]);
    double height = point::length(pp[2], pp[1]);
    return (base + height) * 2;
}

double rectangle::area() const {
    // Also math
    double base = point::length(pp[1], pp[0]);
    double height = point::length(pp[2], pp[1]);
    return base * height;
}