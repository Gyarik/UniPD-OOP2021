#ifndef ORARIO_H_
#define ORARIO_H_

#include <ostream>

class orario {
public:
	// Default constructor
	orario(int =0, int =0, int =0);

	// Methods for hour, minutes and seconds
	int Ore() const;
	int Minuti() const;
	int Secondi() const;

	operator int() { return sec; }

	// Forward time by one hour, second method has side effects
	orario UnOraPiuTardi() const;
	void AvanzaUnOra();

	// Return seconds
	void StampaSecondi() const;

	// Return lunch time :)
	static orario OraDiPranzo();

	// Seconds in an hour and in a day
	static const int Sec_di_una_Ora=3600;
	static const int Sec_di_un_Giorno=86400;

	// Misc operator overloading
	orario operator +(const orario&) const;
	orario operator -(const orario&) const;
	bool operator ==(const orario&) const;
	bool operator <(const orario&) const;
	bool operator >(const orario&) const;

protected:
	// Seconds
	int sec;
};

// << overloading for formatted object print output
std::ostream& operator <<(std::ostream&, const orario&);

#endif