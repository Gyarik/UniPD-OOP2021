#include "bacc.h"

BankAccount::BankAccount(double b) : balance(b) {}

double BankAccount::deposit(double d) {
    return d>=0 ? balance += d : balance;
}

double BankAccount::withdraw(double w) {
    return w>=0 ? balance -= w : balance;
}

double BankAccount::getBal() const {
    return balance;
}


double CurrentAccount::fee = 1.0;

CurrentAccount::CurrentAccount(double b): BankAccount(b) {}

double CurrentAccount::deposit(double d) {
    return BankAccount::deposit(d - fee);
}

double CurrentAccount::withdraw(double w) {
    return BankAccount::withdraw(w + fee);
}


SavingsAccount::SavingsAccount(double b) : BankAccount(b>=0 ? b : 0) {}

double SavingsAccount::withdraw(double w) {
    return BankAccount::withdraw(w>getBal() ? 0 : w);
}


Barclays::Barclays(CurrentAccount& supp, double b) : SavingsAccount(b), suppAcc(supp) {}

double Barclays::deposit(double d) {
    suppAcc.withdraw(d);
    return SavingsAccount::deposit(d);
}

double Barclays::withdraw(double w) {
    if(w <= getBal()) {
        suppAcc.deposit(w);
        return SavingsAccount::withdraw(w);
    }
    return getBal();
}