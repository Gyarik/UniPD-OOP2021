#include <iostream>
#include "telefonata.h"

using std::cout;
using std::endl;

// Constructors
telefonata::telefonata(const orario& i, const orario& f, const int& n) : inizio(i), fine(f), numero(n) {}
telefonata::telefonata() : numero(0) {}

orario telefonata::Inizio() const {
	return inizio;
}

orario telefonata::Fine() const {
	return fine;
}

int telefonata::Numero() const {
	return numero;
}

bool telefonata::operator ==(const telefonata& t) const {
	// Checks if all parameters are equal
	return inizio==t.inizio && fine==t.fine && numero==t.numero;
}

std::ostream& operator <<(std::ostream& os, const telefonata& t) {
	// Cool formatting
	os << "Inizio: " << t.Inizio() << endl << "Fine: " << t.Fine() << endl << "Numero Chiamato: " << t.Numero();
	return os;
}