#include <iostream>
#include "tree.h"

using std::cout;
using std::endl;

int main() {
    albero<char> t1, t2, t3;

    t1.insert('b');
    t1.insert('a');
    
    t2.insert('a');

    t3 = t1;
    t3.insert('c');

    cout << (t1 == t2) << endl;
    cout << t1.search('b') << endl;
    cout << t1 << endl << t2 << endl << t3;
}