#include <iostream>
#include <string>
#include "bolletta.h"

using std::cout;
using std::cin;
using std::endl;

bolletta::nodo::nodo(const telefonata& t, nodo* s) : info(t), next(s) {}

bolletta::nodo::~nodo() {
    if(next != nullptr)
        delete next;
}

bolletta::nodo* bolletta::copia(nodo* p) {
    if(!p)
        return 0;
    else
        return new nodo(p->info, copia(p->next));
}

void bolletta::distruggi(nodo* p) {
    if(p) {
        distruggi(p->next);
        delete p;
    }
}

bool bolletta::iteratore::operator ==(const iteratore& i) const {
    return punt == i.punt;
}

bool bolletta::iteratore::operator !=(const iteratore& i) const {
    return punt != i.punt;
}

bolletta::iteratore& bolletta::iteratore::operator ++() { // ++var
    if(punt)
        punt = punt->next;
    return *this;
}

bolletta::iteratore bolletta::iteratore::operator ++(int) { // var++
    iteratore aux = *this;
    if(punt)
        punt = punt->next;
    return aux;
}

telefonata* bolletta::iteratore::operator ->() const {
    telefonata* aux;
    aux = new telefonata(punt->info);
    return aux;
}

telefonata& bolletta::iteratore::operator *() const {
    return punt->info;
}

bolletta::bolletta() : first(nullptr) {}

bolletta::bolletta(const bolletta& b) : first(copia(b.first)) {}

bool bolletta::Vuota() const {
    return first == 0;
}

void bolletta::Aggiungi_Telefonata(const telefonata& t) {
    first = new nodo(t, first);
}

void bolletta::Togli_Telefonata(const telefonata& t) {
    nodo* p = first, *prec = nullptr;
    while(p && !(p->info == t)) {
        prec = p;
        p = p->next;
    }
    if(p) {
        if(!prec)
            first = p->next;
        else
            prec->next = p->next;
        delete p;
    }
}

telefonata bolletta::Estrai_Una() {
    nodo* p = first;
    telefonata aux = p->info;
    delete p;
    return aux;
}

bolletta& bolletta::operator =(const bolletta& b) {
    if(this != &b) {
        distruggi(first);
        first = copia(b.first);
    }
    return *this;
}

telefonata& bolletta::operator [](const bolletta::iteratore& it) const {
    return (it.punt)->info;
}

bolletta::~bolletta() {
    if(first)
        delete first;
}

bolletta::iteratore bolletta::begin() const {
    bolletta::iteratore aux;
    aux.punt = first;
    return aux;
}

bolletta::iteratore bolletta::end() const {
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
    for(bolletta::iteratore it=b.begin(); it!=b.end(); ++it)
        // durata = durata + (b[it].Fine() - b[it].Inizio());
        // durata = durata + ((*it).Fine() - (*it).Inizio());
        durata = durata + (it->Fine() - it->Inizio());
    return durata;
}

bolletta Chiamate_A(int num, bolletta& b) {
    bolletta selezionate, resto;
    while(!b.Vuota()) {
        telefonata t = b.Estrai_Una();
        if(t.Numero() == num)
            selezionate.Aggiungi_Telefonata(t);
        else
            resto.Aggiungi_Telefonata(t);
    }
    b = resto;
    return selezionate;
}