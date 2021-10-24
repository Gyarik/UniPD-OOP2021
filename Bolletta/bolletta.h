#ifndef BOLLETTA_H_
#define BOLLETTA_H_

#include "telefonata.h"

class bolletta {
private:
    // Nested list class
    class nodo {
    public:
        // nodo(); DEPRECATED
        // Default node constructor
        nodo(const telefonata&, nodo*);
        // List elements
        telefonata info;
        nodo* next;
        // Node destructor
        ~nodo();
    };

    // First node in the list
    nodo* first;

    // Copies node
    static nodo* copia(nodo*);
    // Destroys node
    static void distruggi(nodo*);

public:
    // Nested iterator class
    class iteratore {
        friend class bolletta;
    private:
        // Points at node
        bolletta::nodo* punt;
    public:
        // Misc operator overloading
        bool operator ==(const iteratore&) const;
        bool operator !=(const iteratore&) const;
        iteratore& operator ++();
        iteratore operator ++(int);
        telefonata* operator ->() const;
        telefonata& operator *() const;
    };

    // Constructors
    bolletta();
    bolletta(const bolletta&);

    // Checks if list is empty
    bool Vuota() const;

    // Adds phone call
    void Aggiungi_Telefonata(const telefonata&);
    // Removes phone call
    void Togli_Telefonata(const telefonata&);

    // Extracts a phone call
    telefonata Estrai_Una();

    // Misc operator overloading
    bolletta& operator =(const bolletta&);
    telefonata& operator [](const iteratore&) const;

    // Destructor
    ~bolletta();

    // Indicates list stard and end for iterator
    iteratore begin() const;
    iteratore end() const;
};

// Sums call lengths using iterator
orario Somma_Durate(const bolletta&);

// Returns calls from phone number
bolletta Chiamate_A(int, bolletta&);

#endif