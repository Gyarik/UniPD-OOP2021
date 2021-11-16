#include <iostream>
#include "pol.h"
#include "rect.h"
#include "square.h"
#include "tri.h"

using std::cin;
using std::cout;
using std::endl;

int main() {
    point v[4];
    double x, y;

    cout << "Insert triangle coordinates: " << endl;
    for(int i=0; i<3; i++) {
        cin >> x >> y;
        v[i] = point(x, y);
    }
    const triangle tri(v);

    cout << "Insert rectangle coordinates: " << endl;
    for(int i=0; i<4; i++) {
        cin >> x >> y;
        v[i] = point(x, y);
    }
    rectangle rec1(v), rec2 = rec1;

    cout << "Insert square coordinates: " << endl;
    for(int i=0; i<4; i++) {
        cin >> x >> y;
        v[i] = point(x, y);
    }
    square sq1(v), sq2 = sq1;

    cout << "Triangle:\n" << tri.perimeter() << '\t' << tri.area() << endl;
    cout << "Rectangle:\n" << rec2.perimeter() << '\t' << rec2.area() << endl;
    cout << "Square:\n" << sq2.perimeter() << '\t' << sq2.area() << endl;

    // OLD TEST
    // point p1(1, 1);
    // point p2(2, 2);
    // point p3(1, 3);

    // point p4(p1);
    // point p5(1, 2);
    // point p6(p2);
    // point p7(2, 1);

    // cout << point::length(p1, p2) << endl;
    // cout << point::length(p2, p3) << endl;
    // cout << point::length(p3, p1) << endl << endl;

    // cout << point::length(p4, p5) << endl;
    // cout << point::length(p5, p6) << endl;
    // cout << point::length(p6, p7) << endl;
    // cout << point::length(p7, p4) << endl << endl;

    // point* v = new point[3]{p1, p2, p3};
    // point* u = new point[4]{p4, p5, p6, p7};
    
    // // Triangle
    // polygon pol1(3, v);
    // cout << pol1.perimeter() << endl;   // 4.8-something

    // // Square
    // polygon pol2(4, u);
    // cout << pol2.perimeter() << endl;   // 4

    // // pol2 should become pol1
    // pol2 = pol1;
    // cout << pol2.perimeter() << endl;   // Same as pol1

    // // Proper square
    // square sqr(u);
    // cout << sqr.perimeter() << endl;    // Same as pol2
    // cout << sqr.area() << endl;         // 1

    return 0;
}