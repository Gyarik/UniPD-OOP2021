#include <iostream>
#include "queue.h"

using std::cout;
using std::endl;

int main() {
    Queue<int>* pi = new Queue<int>;

    for(int i=0; i<10; i++)
        pi->add(i);

    for(int i=0; i<10; i++)
        cout << pi->remove() << endl;

    return 0;
}