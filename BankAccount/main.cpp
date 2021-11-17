#include <iostream>
#include "bacc.h"

using std::cout;
using std::endl;

int main() {
    CurrentAccount cc(2000);
    Barclays ca(cc, 1500);

    ca.deposit(350);
    ca.withdraw(400);
    cc.withdraw(150);

    cout << cc.getBal() << endl;
    cout << ca.getBal() << endl;
}