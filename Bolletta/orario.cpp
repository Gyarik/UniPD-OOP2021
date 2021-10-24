#include <iostream>
#include <iomanip>
#include "orario.h"

using std::cout;
using std::cin;
using std::endl;


orario::orario (int h, int m, int s) {
	if(h<0 || h>23 || m<0 || m>59 || s<0 || s>59)
		sec=0;
	else
		sec=(h*60*60)+(m*60)+s;
}

int orario::Ore() const {
	return sec/3600;
}

int orario::Minuti() const {
	return (sec/60)%60;
}

int orario::Secondi() const {
	return sec%60;
}

orario orario::UnOraPiuTardi() const {
	orario aux;
	aux.sec=(sec+3600)%86400;
	return aux;
}

void orario::AvanzaUnOra() { //Side Effects
	sec=(sec+3600)%86400;
}

void orario::StampaSecondi() const {
	cout << sec << endl;
}

orario orario::OraDiPranzo() {
	return orario(13, 15);
}

orario orario::operator +(const orario& o) const {
	orario aux;
	aux.sec=(sec+o.sec)%86400;
	return aux;
}

orario orario::operator -(const orario& o) const {
	orario aux;
	aux.sec = (sec - o.sec) % 86400;
	if(aux.sec < 0) {
		aux.sec = 86400 + aux.sec;
	}
	return aux;
}

bool orario::operator ==(const orario& o) const {
	return sec == o.sec;
}

bool orario::operator <(const orario& o) const {
	return sec < o.sec;
}

bool orario::operator >(const orario& o) const {
	return sec > o.sec;
}

std::ostream& operator <<(std::ostream& os, const orario& o) {
//	os << "ore ";
	os << std::setw(2) << std::setfill('0') << o.Ore() << ":";
	os << std::setw(2) << std::setfill('0') << o.Minuti() << ":";
	os << std::setw(2) << std::setfill('0') << o.Secondi();
//	os << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi();
	return os;
}