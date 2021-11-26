#include <iostream>
#include "workers.h"

using std::cout;
using std::endl;


Worker::Worker(string n) : name(n) {};

Worker::~Worker() {};   // Useless lol

string Worker::getName() const {
    return name;
}

void Worker::printInfo() const {
    cout << name;
}


Director::Director(string n, double f) : Worker(n), fixedPay(f) {}

double Director::pay() const {
    return fixedPay;
}

void Director::printInfo() const {
    cout << "Director ";
    // Static method invoked thanks to abstractification
    Worker::printInfo();
}


Representative::Representative(string n, double b, double c, int t) :
    Worker(n), basePay(b), commission(c), sold(t) {}

double Representative::pay() const {
    return basePay + commission * sold;
}

void Representative::printInfo() const {
    cout << "Representative ";
    // Static method invoked thanks to abstractification
    Worker::printInfo();
}


WorkerHours::WorkerHours(string n, double p, double h) :
    Worker(n), hourlyPay(p), hoursMonth(h) {}

double WorkerHours::pay() const {
    if(hoursMonth <= 160)
        return hourlyPay * hoursMonth;
    else
        return 160 * hourlyPay + (hoursMonth - 160) * 2 * hourlyPay;
}

void WorkerHours::printInfo() const {
    cout << "Hourly Worker ";
    // Static method invoked thanks to abstractification
    Worker::printInfo();
}

void printPay(const Worker& w) {
    w.printInfo();
    cout << " gained " << w.pay() << " Euro this month." << endl;
}