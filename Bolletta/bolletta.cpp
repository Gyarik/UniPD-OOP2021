#include <iostream>
#include <string>
#include "bolletta.h"

using std::cout;
using std::cin;
using std::endl;

// Node constructor
bolletta::nodo::nodo(const telefonata& t, nodo* s) : info(t), next(s) {}

bolletta::nodo::~nodo() {
    // Deletes pointer to next node as long as it isn't null (last node)
    if(next != nullptr)
        delete next;
}

bolletta::nodo* bolletta::copia(nodo* p) {
    // If node exists return copy of parameter
    if(!p)
        return 0;
    else
        return new nodo(p->info, copia(p->next));
}

void bolletta::distruggi(nodo* p) {
    // If node exists destroy pointer to next node, then node
    if(p) {
        distruggi(p->next);
        delete p;
    }
}

bool bolletta::iteratore::operator ==(const iteratore& i) const {
    // Logic comparison between pointers
    return punt == i.punt;
}

bool bolletta::iteratore::operator !=(const iteratore& i) const {
    // Ditto
    return punt != i.punt;
}

bolletta::iteratore& bolletta::iteratore::operator ++() {   // ++var
    // Increments, then returns invoked object
    if(punt)
        punt = punt->next;
    return *this;
}

bolletta::iteratore bolletta::iteratore::operator ++(int) { // var++
    // aux to return original value first, then increment
    iteratore aux = *this;
    if(punt)
        punt = punt->next;
    return aux;
}

telefonata* bolletta::iteratore::operator ->() const {
    // Makes iteration more readable through -> operator
    telefonata* aux;
    aux = new telefonata(punt->info);
    return aux;
}

telefonata& bolletta::iteratore::operator *() const {
    // Ditto but with * operator
    return punt->info;
}

// Constructors
bolletta::bolletta() : first(nullptr) {}
bolletta::bolletta(const bolletta& b) : first(copia(b.first)) {}

bool bolletta::Vuota() const {
    // Checks if null
    return first == 0;
}

void bolletta::Aggiungi_Telefonata(const telefonata& t) {
    // Adds parameter (phone call) to list
    first = new nodo(t, first);
}

void bolletta::Togli_Telefonata(const telefonata& t) {
    // Removes parameter (phone call) from list
    nodo* p = first, *prec = nullptr;
    // If node exists and calls don't match, shift list
    while(p && !(p->info == t)) {
        prec = p;
        p = p->next;
    }
    // Final checks before deleting call
    if(p) {
        if(!prec)
            first = p->next;
        else
            prec->next = p->next;
        delete p;
    }
}

telefonata bolletta::Estrai_Una() {
    // Extracts call from first node
    nodo* p = first;
    telefonata aux = p->info;
    delete p;
    return aux;
}

bolletta& bolletta::operator =(const bolletta& b) {
    // If objects are not already equal, copy from first node
    if(this != &b) {
        distruggi(first);
        first = copia(b.first);
    }
    return *this;
}

telefonata& bolletta::operator [](const bolletta::iteratore& it) const {
    // Makes iteration easier with array-like properties
    return (it.punt)->info;
}

bolletta::~bolletta() {
    // Deletes first node
    if(first)
        delete first;
}

bolletta::iteratore bolletta::begin() const {
    // Returns list start
    bolletta::iteratore aux;
    aux.punt = first;
    return aux;
}

bolletta::iteratore bolletta::end() const {
    // Returns list end + 1 (nullptr)
    bolletta::iteratore aux;
    aux.punt = nullptr;
    return aux;
}

// DEPRECATED
// orario Somma_Durate(bolletta b) {
//     orario durata;
//     while(!b.Vuota()) {
//         telefonata t = b.Estrai_Una();
//         durata = durata + t.Fine() - t.Inizio();
//     }
//     return durata;
// }

orario Somma_Durate(const bolletta& b) {
    orario durata;
    // Three ways of summing using operator overloading ([], *, ->)
    for(bolletta::iteratore it=b.begin(); it!=b.end(); ++it)
        // durata = durata + (b[it].Fine() - b[it].Inizio());
        // durata = durata + ((*it).Fine() - (*it).Inizio());
        durata = durata + (it->Fine() - it->Inizio());
    return durata;
}

bolletta Chiamate_A(int num, bolletta& b) {
    bolletta selezionate, resto;
    // If list is not empty, extract all calls from one number
    while(!b.Vuota()) {
        telefonata t = b.Estrai_Una();
        if(t.Numero() == num)
            selezionate.Aggiungi_Telefonata(t);
        else
            resto.Aggiungi_Telefonata(t);
    }
    // Replace parameter object with remainder using overloaded =
    b = resto;
    return selezionate;
}