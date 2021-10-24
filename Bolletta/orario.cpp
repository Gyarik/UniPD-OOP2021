#include <iostream>
#include <iomanip>
#include "orario.h"

using std::cout;
using std::endl;

orario::orario (int h, int m, int s) {
	// If input does not conform, default to midnight
	if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
		sec=0;
	else
		sec=(h*60*60)+(m*60)+s;
}

int orario::Ore() const {
	// Returns hours
	return sec/3600;
}

int orario::Minuti() const {
	// Returns minutes
	return (sec/60)%60;
}

int orario::Secondi() const {
	// Returns seconds
	return sec%60;
}

orario orario::UnOraPiuTardi() const {
	// Uses auxiliary object to avoid side effects
	orario aux;
	aux.sec=(sec+3600)%86400;
	return aux;
}

void orario::AvanzaUnOra() {
	// Same as above, but with side effects
	sec=(sec+3600)%86400;
}

void orario::StampaSecondi() const {
	// Prints private int
	cout << sec << endl;
}

orario orario::OraDiPranzo() {
	// Returns lunch time :)
	return orario(13, 15);
}

orario orario::operator +(const orario& o) const {
	// Uses auxiliary object to avoid side effects
	orario aux;
	aux.sec=(sec+o.sec)%86400;
	return aux;
}

orario orario::operator -(const orario& o) const {
	// Uses auxiliary object to avoid side effects
	orario aux;
	aux.sec = (sec - o.sec) % 86400;
	if(aux.sec < 0) {
		aux.sec = 86400 + aux.sec;
	}
	return aux;
}

bool orario::operator ==(const orario& o) const {
	// Compares both objects by their seconds values
	return sec == o.sec;
}

bool orario::operator <(const orario& o) const {
	// Ditto
	return sec < o.sec;
}

bool orario::operator >(const orario& o) const {
	// Ditto
	return sec > o.sec;
}

std::ostream& operator <<(std::ostream& os, const orario& o) {
	// Cool formatting
//	os << "ore ";
	os << std::setw(2) << std::setfill('0') << o.Ore() << ":";
	os << std::setw(2) << std::setfill('0') << o.Minuti() << ":";
	os << std::setw(2) << std::setfill('0') << o.Secondi();
//	os << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi();
	return os;
}