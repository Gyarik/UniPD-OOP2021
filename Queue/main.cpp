#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

int main() {
    Queue<int> pi;

    for(int i=0; i<10; i++)
        pi.add(i);

    Queue<int> pi2;

    for(int i=10; i>0; i--)
        pi2.add(i);

    pi2 = pi;

    for(int i=0; i<10; i++)
        cout << pi.remove() << endl;

    for(int i=0; i<10; i++)
        cout << pi2.remove() << endl;

    return 0;
}