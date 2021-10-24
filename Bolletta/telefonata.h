#ifndef TELEFONATA_H_
#define TELEFONATA_H_

#include <ostream>
#include "orario.h"

class telefonata {
private:
	// Call start timestamp
	orario inizio;
	// Call end timestamp
	orario fine;
	// Phone number
	int numero;

public:
	// Constructors
	telefonata();
	telefonata(const orario& =0, const orario& =0, const int& =0);
	// Returns start timestamp
	orario Inizio() const;
	// Returns end timestamp
	orario Fine() const;
	// Returns phone number
	int Numero() const;
	// == overloading
	bool operator ==(const telefonata&) const;
};

// << overloading for formatted object print output
std::ostream& operator <<(std::ostream&, const telefonata&);


#endif /* TELEFONATA_H_ */