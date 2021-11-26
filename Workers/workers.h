#ifndef WORKERS_H_
#define WORKERS_H_

#include <string>

using std::string;

// Base abstract worker class
class Worker {
private:
    // Worker's name
    string name;
public:
    // Constructor (name)
    Worker(string);
    // Kinda useless destructor but it's just there
    virtual ~Worker();
    // Name getter method
    string getName() const;
    // Return pay (0 since it's base abstract class)
    virtual double pay() const = 0;
    // Print info about worker (name)
    virtual void printInfo() const;
};

// Derived Director class
class Director : public Worker {
private:
    // Director's Pay (fixed value)
    double fixedPay;
public:
    // Constructor (name, pay)
    Director(string, double =0);
    // Return pay (overriding)
    double pay() const;
    // Print info about director (overriding)
    void printInfo() const;
};

// Derived Representative class
class Representative : public Worker {
private:
    // Base pay (fixed value)
    double basePay;
    // Commission for each item sold
    double commission;
    // Number of items sold
    int sold;
public:
    // Constructor (name, base pay, commission, items sold)
    Representative(string, double =0, double =0, int =0);
    // Return pay (overriding)
    double pay() const;
    // Print info about representative (overriding)
    void printInfo() const;
};

// Derived Hourly Worker class
class WorkerHours : public Worker {
private:
    // Hourly pay (fixed value)
    double hourlyPay;
    // Hours worked for month
    double hoursMonth;
public:
    // Constructor (name, hourly pay, hours)
    WorkerHours(string, double =0, double =0);
    // Return pay (overriding)
    double pay() const;
    // Print info about worker (overriding)
    void printInfo() const;
};

// External function for printing someone's pay
void printPay(const Worker&);

#endif