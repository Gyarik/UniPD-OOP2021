#ifndef BACC_H_
#define BACC_H_

class BankAccount {
private:
    double balance;
public:
    BankAccount(double =0);
    double deposit(double);
    double withdraw(double);
    double getBal() const;
};

class CurrentAccount : public BankAccount {
private:
    static double fee;
public:
    CurrentAccount(double =0);
    double deposit(double);
    double withdraw(double);
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(double =0);
    double withdraw(double w);
};

class Barclays : public SavingsAccount {
private:
    CurrentAccount& suppAcc;
public:
    Barclays(CurrentAccount&, double =0);
    double deposit(double);
    double withdraw(double);
};

#endif