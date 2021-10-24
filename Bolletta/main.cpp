#include <iostream>
#include <iomanip>
#include "orario.h"
#include "telefonata.h"
#include "bolletta.h"
#include "templates.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	orario Mezzanotte;
	orario Adesso(1, 23, 30);
	// cout << Adesso.Ore() << ":" << Adesso.Minuti() << ":" << Adesso.Secondi() << endl;
	// int x=Adesso;
	// cout << x << " Secondi" << endl;

	// Adesso.StampaSecondi();

	// cout << "Ora di pranzo: " << orario::OraDiPranzo().Ore() << ":" << orario::OraDiPranzo().Minuti() << endl;

	// orario Ora(22, 45);
	// orario OraF(23, 45);
	// orario DUE_ORE_E_UN_QUARTO(2, 15);
	// Ora=Ora+DUE_ORE_E_UN_QUARTO;
	// cout << Ora.Ore() << ":" << Ora.Minuti() << endl;
	// cout << Ora << endl;

	// cout << Mezzanotte << endl;

	// cout << (Ora == DUE_ORE_E_UN_QUARTO);
	// cout << (Ora > DUE_ORE_E_UN_QUARTO);
	// cout << (Ora < DUE_ORE_E_UN_QUARTO) << endl << endl;


	cout << "TELEFONATA" << endl << endl;

	telefonata TIMGyarik(orario(12, 30), orario(12, 45), 1);
	telefonata FastwebGyarik(orario(13, 30), orario(13, 38), 2);
	telefonata EoloGyarik(orario(15, 45), orario(16, 10), 3);
	cout << TIMGyarik << endl << endl << FastwebGyarik << endl << endl << EoloGyarik << endl;

	cout << endl << endl;

	cout << "BOLLETTA" << endl << endl;

	bolletta Gyarik;
	Gyarik.Aggiungi_Telefonata(TIMGyarik);
	Gyarik.Aggiungi_Telefonata(FastwebGyarik);
	Gyarik.Aggiungi_Telefonata(EoloGyarik);

	cout << "Somma: " << Somma_Durate(Gyarik);

	cout << endl << endl;

	cout << min(9, 3) << min(3*16, 50-2) << endl;
	cout << min(orario(4), orario(4, 5, 6)) << endl;

	return 0;
}