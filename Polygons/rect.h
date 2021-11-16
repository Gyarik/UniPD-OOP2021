#ifndef RET_H_
#define RET_H_

#include "pol.h"

// Rectangle subclass (specific polygon case)
class rectangle : public polygon {
public:
    // Constructor
    rectangle(const point v[]);
    // Perimeter
    double perimeter() const;
    // Area
    double area() const;
};

#endif