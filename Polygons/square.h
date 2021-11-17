#ifndef SQUARE_H_
#define SQUARE_H_

#include "rect.h"

// Square subclass (specific rectangle case)
class square : public rectangle {
public:
    // Constructor
    square(const point v[] =0);
    // Perimeter
    double perimeter() const;
    // Area
    double area() const;
};

#endif