#ifndef RECT_H_
#define RECT_H_

#include "pol.h"

// Rectangle subclass (specific polygon case)
class rectangle : public polygon {
public:
    // Constructor
    rectangle(const point v[] =0);
    // Perimeter
    double perimeter() const;
    // Area
    double area() const;
};

#endif