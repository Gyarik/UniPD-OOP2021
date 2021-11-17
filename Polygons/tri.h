#ifndef TRI_H_
#define TRI_H_

#include "pol.h"

class triangle : public polygon {
public:
    triangle(const point v[] =0);
    double area() const;
};

#endif