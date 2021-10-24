#ifndef TELEFONATA_H_
#define TELEFONATA_H_

#include <ostream>
#include "orario.h"

class telefonata {
private:
	orario inizio;
	orario fine;
	int numero;

public:
	telefonata();
	telefonata(const orario& =0, const orario& =0, const int& =0);
	orario Inizio() const;
	orario Fine() const;
	int Numero() const;
	bool operator ==(const telefonata&) const;
};

std::ostream& operator <<(std::ostream&, const telefonata&);


#endif /* TELEFONATA_H_ */