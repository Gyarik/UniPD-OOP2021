#ifndef BOLLETTA_H_
#define BOLLETTA_H_

#include "telefonata.h"

class bolletta {
private:
    class nodo {
    public:
        // nodo();
        nodo(const telefonata&, nodo*);
        telefonata info;
        nodo* next;

        ~nodo();
    };

    nodo* first;
    static nodo* copia(nodo*);
    static void distruggi(nodo*);

public:
    class iteratore {
        friend class bolletta;
    private:
        bolletta::nodo* punt;
    public:
        bool operator ==(const iteratore&) const;
        bool operator !=(const iteratore&) const;
        iteratore& operator ++();
        iteratore operator ++(int);
        telefonata* operator ->() const;
        telefonata& operator *() const;
    };

    bolletta();
    bolletta(const bolletta&);
    bool Vuota() const;
    void Aggiungi_Telefonata(const telefonata&);
    void Togli_Telefonata(const telefonata&);
    telefonata Estrai_Una();

    bolletta& operator =(const bolletta&);
    telefonata& operator [](const iteratore&) const;

    ~bolletta();

    iteratore begin() const;
    iteratore end() const;
};

orario Somma_Durate(const bolletta&);
bolletta Chiamate_A(int, bolletta&);

#endif