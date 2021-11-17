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
    // Root node
    nodo* root;

    // Copies nodes
    static nodo* copia(nodo* r) {
        // Deep copy
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
        // Search for equal data through nodes (recursively)
        if(!r)
            return false;
        return r->info == t || search_rec(r->sx, t) || search_rec(r->cx, t) || search_rec(r->dx, t);
    }

    // Checks if nodes are equal
    static bool equal_rec(nodo* r1, nodo* r2) {
        // If both nodes don't exist, return true
        if(!r1 && !r2)
            return true;
        // If only one doesn't exist, return false
        if(!r1 || !r2)
            return false;
        // Otherwise search through every node (recursively)
        return r1->info == r2->info && equal_rec(r1->sx, r2->sx) && equal_rec(r1->cx, r2->cx) &&
            equal_rec(r1->dx, r2->dx);
    }

    // Prints data
    static std::ostream& print_rec(std::ostream& os, nodo* r) {
        // Recursive tree ostream, used for << overloading
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
        // Original invoked object tree destruction, then deep copy
        if(this != &a) {
            if(root)
                distruggi(root);
            root = copia(a.root);
        }
        return *this;
    }

    // Destructor
    ~albero() {
        // Deep destruction
        if(root)
            distruggi(root);
    }

    // Inserts data into tree
    void insert(const T& x) {
        // Proper insertion with deep copy
        root = new nodo(x, copia(root), copia(root), root);
    }

    // Searches data into tree
    bool search(const T& t) const {
        // Check already done in search_rec
        return search_rec(root, t);
    }

    // == overloading
    bool operator ==(const albero& a) const {
        // Check already done in equal_rec
        return equal_rec(root, a.root);
    }
};

// Template << overloading
template <class T> std::ostream& operator <<(std::ostream& os, const albero<T>& a) {
    // Tree print already done in print_rec
    return albero<T>::print_rec(os, a.root);
}

#endif