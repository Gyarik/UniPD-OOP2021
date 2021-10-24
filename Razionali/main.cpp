#include <iostream>
#include "Raz.h"
using std::cout;
using std::endl;

int main() {
    Raz x(2, 3), y(2), z, u(1, 8), v(3, 2), w(8, 4);

    cout << x + y + v*u << endl;    // 2.85417
    cout << u.inverso() << endl;    // 8
    cout << (y == w) << endl;       // true (1)
    cout << y++ << ' ' << ++w << endl;  // 2 3
    cout << (++y + Raz::unTerzo()) << endl; // 4.33333
    cout << 2 + Raz(1, 2) << endl;  // 2.5

    return 0;
}