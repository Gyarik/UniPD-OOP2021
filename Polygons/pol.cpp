#include <cmath>
#include "pol.h"

using std::pow;
using std::sqrt;

point::point(double a, double b) : x(a), y(b) {}
point::point(const point& p) : x(p.x), y(p.y) {}

double point::length(const point& p1, const point& p2) {
    // Math or something (idk I've only got a 20/30 in Calc 1 or Analysis 1 w/e)
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

const point* polygon::copy(unsigned int n, const point* p) {
    // Auxiliary point array for deep iterative copy
    point* v = new point[n];
    for(unsigned int i=0; i<n; ++i) {
        v[i] = point(p[i]);
    }
    return v;
}

polygon::polygon(unsigned int n, const point v[]) : nvertex(n), pp(polygon::copy(nvertex, v)) {}

polygon::~polygon() {
    // I guess it's how it works? Not sure
    delete[] pp;
}

polygon::polygon(const polygon& pol): nvertex(pol.nvertex), pp(polygon::copy(nvertex, pol.pp)) {}

polygon& polygon::operator =(const polygon& pol) {
    // Return invoked object with copied parameters
    nvertex = pol.nvertex;
    pp = copy(nvertex, pol.pp);
    return *this;
}

double polygon::perimeter() const {
    double p = 0;
    for(unsigned int i=0; i<nvertex; ++i) {
        // Before adding length, check if 'final' vertex is reached
        if(i+1 < nvertex)
            p += point::length(pp[i], pp[i+1]);
        else
            p += point::length(pp[i], pp[0]);
    }
    return p;
}
