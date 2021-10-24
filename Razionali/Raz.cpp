#include <ostream>
#include "Raz.h"

// Constructor (den cannot be 0)
Raz::Raz(int n, int d) : num(n), den(d==0 ? 1 : d) {}

Raz Raz::inverso() const {
    // New den is already !=0, so check new num instead
    return Raz(num==0 ? 0 : den, num);
}

Raz::operator double() const {
    // Simple static cast
    return static_cast<double>(num) / static_cast<double>(den);
}

Raz Raz::operator +(const Raz& r) const {
    return Raz(num*r.den + r.num*den, den*r.den);
}

Raz Raz::operator *(const Raz& r) const {
    return Raz(num*r.num, den*r.den);
}

bool Raz::operator ==(const Raz& r) const {
    return num*r.den == den*r.num;
}

Raz& Raz::operator ++() {   // ++var
    // Directly returns incremented value
    num += den;
    return *this;
}

Raz Raz::operator ++(int) { // var++
    // Returns old value, then increments
    Raz aux(*this);
    num += den;
    return aux;
}

Raz Raz::unTerzo() {
    return Raz(1, 3);
}

std::ostream& operator <<(std::ostream& os, const Raz& r) {
    // Quick conversion to double on print
    return os << r.operator double();
}