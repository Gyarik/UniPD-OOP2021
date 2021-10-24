#ifndef RAZ_H_
#define RAZ_H_

#include <ostream>

class Raz {
private:
    // Numerator and denominator integers
    int num, den;

public:
    // Constructor
    explicit Raz(int =0, int =1);

    // Inverts fraction
    Raz inverso() const;

    // Converts object to double
    operator double() const;

    // Misc operator overloading
    Raz operator +(const Raz&) const;
    Raz operator *(const Raz&) const;
    bool operator ==(const Raz&) const;
    Raz& operator ++();
    Raz operator ++(int);

    // Literally returns 1/3
    static Raz unTerzo();
};

// << overloading for formatted object print output
std::ostream& operator <<(std::ostream&, const Raz&);

#endif