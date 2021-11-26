#include <iostream>
#include "workers.h"

using std::cout;
using std::endl;

int main() {
    Director d("John", 4000);
    Representative r("Julie", 1000, 3, 250);
    WorkerHours w("Mark", 15, 170);

    printPay(d);
    printPay(r);
    printPay(w);

    return 0;
}