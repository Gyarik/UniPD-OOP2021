#include <cmath>
#include "tri.h"

triangle::triangle(const point v[]) : polygon(3, v) {}

double triangle::area() const {
    // Heron's formula
    double p = perimeter() / 2;
    double a = point::length(pp[1], pp[0]);
    double b = point::length(pp[2], pp[1]);
    double c = point::length(pp[0], pp[2]);
    return std::sqrt(p*(p-a)*(p-b)*(p-c));
}