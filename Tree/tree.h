#ifndef TREE_H_
#define TREE_H_

#include <iostream>

// Incomplete declaration
template <class T> class albero;

// Template << overloading (incomplete declaration)
template <class T> std::ostream& operator <<(std::ostream& os, const albero<T>& a);

// Tree template class
template <class T> class albero {
friend std::ostream& operator << <T>(std::ostream&, const albero&);
private:
    class nodo {
    public:
        // Data
        T info;
        // Pointers to left, center and right nodes
        nodo *sx, *cx, *dx;
        // Constructor
        nodo(const T& t, nodo* _sx =0, nodo* _cx =0, nodo* _dx =0) :
            info(t), sx(_sx), cx(_cx), dx(_dx) {}
    };
    // Rood node
    nodo* root;

    // Copies node
    static nodo* copia(nodo* r) {
        if(!r)
            return nullptr;
        return new nodo(r->info, copia(r->sx), copia(r->cx), copia(r->dx));
    }

    // Destroys nodes
    static void distruggi(nodo* r) {
        // Deep destruction
        if(r) {
            distruggi(r->sx);
            distruggi(r->cx);
            distruggi(r->dx);
            delete r;
        }
    }

    // Searches data through nodes
    static bool search_rec(nodo* r, const T& t) {
        if(!r)
            return false;
        return r->info == t || search_rec(r->sx, t) || search_rec(r->cx, t) || search_rec(r->dx, t);
    }

    // Checks if nodes are equal
    static bool equal_rec(nodo* r1, nodo* r2) {
        if(!r1 && !r2)
            return true;
        if(!r1 || !r2)
            return false;
        return r1->info == r2->info && equal_rec(r1->sx, r2->sx) && equal_rec(r1->cx, r2->cx) &&
            equal_rec(r1->dx, r2->dx);
    }

    // Prints data
    static std::ostream& print_rec(std::ostream& os, nodo* r) {
        if(!r)
            return os;
        os << r->info << ' ';
        print_rec(os, r->sx);
        print_rec(os, r->cx);
        return print_rec(os, r->dx);
    }

public:
    // Constructors
    albero() : root(nullptr) {}
    albero(const albero& a) : root(copia(a.root)) {}

    // = overloading
    albero& operator =(const albero& a) {
        if(this != &a) {
            if(root)
                distruggi(root);
            root = copia(a.root);
        }
        return *this;
    }

    // Destructor
    ~albero() {
        if(root)
            distruggi(root);
    }

    // Inserts data into tree
    void insert(const T& x) {
        root = new nodo(x, copia(root), copia(root), root);
    }

    // Searches data into tree
    bool search(const T& t) const {
        return search_rec(root, t);
    }

    // == overloading
    bool operator ==(const albero& a) const {
        return equal_rec(root, a.root);
    }
};

// Template << overloading
template <class T> std::ostream& operator <<(std::ostream& os, const albero<T>& a) {
    return albero<T>::print_rec(os, a.root);
}

#endif