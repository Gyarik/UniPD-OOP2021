#include <iostream>
#include "dList.h"

int main() {
    dList<int> x(4,2), y(0,0), z(6,8);
    y=x;
    x.insertFront(-2); z.insertFront(3); y.insertFront(0);
    if(x<y) std::cout << "x < y" << std::endl;
    if(z<x) std::cout << "z < x" << std::endl;
    if(y<z) std::cout << "y < z" << std::endl;
    if(z<y) std::cout << "z < y" << std::endl;

    std::cout << "x= ";
    dList<int>::const_iterator j = --(x.end());
    for(; j != x.begin(); --j) std::cout << *j << ' '; 
    std::cout << *j << std::endl << "y= ";
    for(dList<int>::const_iterator k = y.begin(); k != y.end(); ++k) std::cout << *k << ' ';  
    std::cout << std::endl << "z= ";
    dList<int>::const_iterator i = z.begin(); 
    for( ; i != z.end(); ++i) std::cout << *i << ' ' << std::endl;
}