#include "dataora.h"
#include "orario.h"

dataora::dataora(int a, int me, int g, int o, int m, int s) : orario(o, m, s), anno(a) {
    // Checks for month and day to not be impossible values
    if(me<1 || me>12)
        mese = 1;
    else
        mese = me;
    if(g<0 || g>31 || GiorniDelMese()<g)
        giorno = 1;
    else
        giorno = g;
}

// Self-explanatory
int dataora::Giorno() const {
    return giorno;
}
int dataora::Mese() const {
    return mese;
}
int dataora::Anno() const {
    return anno;
}

int dataora::GiorniDelMese() const {
    // Check amount of days depending on invoked object's month
    if(mese == 1 || mese == 3 || mese == 5 || mese == 7 ||
    mese == 8 || mese == 10 || mese == 12)
        return 31;
    if(mese == 4 || mese == 6 || mese == 9 || mese == 11)
        return 30;
    if(!(anno % 400))
        return 29;
    return 28;
}

void dataora::AvanzaUnGiorno() {
    // If day is strictly less than amount of days per month, increment day
    if(giorno < GiorniDelMese())
        giorno++;
    // Otherwise if month is less than 12, set to first day of the next month
    else if(mese < 12) {
        giorno = 1;
        mese++;
    }
    // Otherwise set to first day of the first month of the next year
    else {
        giorno = 1;
        mese = 1;
        anno++;
    }
}

dataora dataora::operator +(const orario& o) const {
    // Auxiliary object to avoid side effects
    dataora aux = *this;
    // aux.sec = o.sec is inaccessible, instead invoke public methods
    aux.sec = sec + 3600*o.Ore() + 60*o.Minuti() + o.Secondi();
    // If seconds are too many for a day, set proper seconds and add a day
    if(aux.sec >= 86400) {
        aux.sec = aux.sec - 86400;
        aux.AvanzaUnGiorno();
    }
    return aux;
}

// lol
giornosett dataorasett::GiornoSettimana() const {
    return giornosettimana;
}