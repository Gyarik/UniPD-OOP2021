#ifndef POL_H_
#define POL_H_

// Point class
class point {
private:
    // x and y coordinates
    double x, y;
public:
    // Default constructor
    point(double =0, double =0);
    // Copy constructor
    point(const point&);
    // Calculate length between two points
    static double length(const point&, const point&);
};

// Polygon class
class polygon {
private:
    // Deep copy of polygon parameters
    static const point* copy(unsigned int, const point*);
protected:
    // Number of vertexes
    unsigned int nvertex;
    // Array of (ordered) points
    const point* pp;
public:
    // Default constructor
    polygon(unsigned int, const point*);
    // Default destructor
    ~polygon();
    // Copy constructor
    polygon(const polygon&);
    // Operator = overloading (copy parameter object to invoked one)
    polygon& operator =(const polygon&);
    // Calculate invoked object's perimeter
    double perimeter() const;
};

#endif