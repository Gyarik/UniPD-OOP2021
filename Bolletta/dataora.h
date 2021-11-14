#ifndef DATAORA_H_
#define DATAORA_H_

#include "orario.h"

// Useless enum for days in a week lol
enum giornosett {lun, mar, mer, gio, ven, sab, dom};

// Date and time class, subclass of orario
class dataora : public orario {
private:
    // Day
    int giorno;
    // Month
    int mese;
    // Year
    int anno;
public:
    // Default constructor (year, month, day, hour, minute, second)
    dataora(int =2000, int =1, int =1, int =0, int =0, int =0);

    // Return day
    int Giorno() const;
    // Return month
    int Mese() const;
    // Return year
    int Anno() const;

    // Return correct amount of days for each month
    int GiorniDelMese() const;
    // +1 day
    void AvanzaUnGiorno();

    // Operator + overloading
    dataora operator +(const orario&) const;
};

// A subclass of dataora (for demonstration purposes)
class dataorasett : public dataora {
public:
    // Return day in a week
    giornosett GiornoSettimana() const;
private:
    // Day in a week
    giornosett giornosettimana;
};

#endif