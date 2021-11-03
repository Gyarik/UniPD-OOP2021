#ifndef DLIST_H_
#define DLIST_H_

template <class T> class dList {
private:
    class node {
    public:
        // Data
        T info;
        // Pointers to previous and next node
        node *prev, *next;
        // Constructor
        node(const T& t, node* p =0, node* n =0) : info(t), prev(p), next(n) {}
    };
    // Pointers to first and last node
    node *first, *last;

    // Deep node copy
    static node* copy(node* n, node*& last, node* prev =nullptr) {
        // If node is null return last node as null
        if(n == nullptr)
            return last = nullptr;
        // Otherwise use aux to copy and recursively copy the previous node (backwards copy)
        node* aux = new node(n->info, prev, nullptr);
        aux->next = copy(n->next, last, aux);
        if(n->next == nullptr)
            last = aux;
        return aux;
    }

    // Compare n1 < n2
    static bool isLess(node* n1, node* n2) {
        // If n2 is null then n1 is surely not less than n2
        if(n2 == nullptr)
            return false;
        // If n1 is null then n1 is surely less than n2
        if(n1 == nullptr)
            return true;
        // Otherwise data comparison and recursively compare next nodes
        return (n1->info < n2->info) || ((n1->info == n2->info) &&
            isLess(n1->next, n2->next));
    }

    // Deep destruction
    static void destroy(node* n) {
        // Recursion
        if(n != nullptr) {
            destroy(n->next);
            delete n;
        }
    }

public:
    // Constructor
    dList(const dList& d) : last(nullptr), first(copy(d.first, last)) {}

    // Operator = overloading
    dList& operator =(const dList& d) {
        // If lists are not already equal, invoke copy
        if(this != &d) {
            destroy(first);
            first = copy(d.first, last);
        }
        return *this;
    }

    // Destructor
    ~dList() {
        if(first)
            destroy(first);
    }

    // Insert node from first place
    void insertFront(const T& t) {
        // Place new first node
        first = new node(t, nullptr, first);
        if(last == nullptr)
            last = first;
        else
            first->next->prev = first;
    }

    // Insert node from last place
    void insertBack(const T& t) {
        // If last node exists, place new last node
        if(last) {
            last = new node(t, last, nullptr);
            last->prev->next = last;
        }
        // Otherwise first and last node are equal to new node
        else
            first = last = new node(t);
    }

    // Special copy constructor: create k nodes all containing data t
    dList(unsigned int k =0, const T& t =T()) : last(nullptr), first(nullptr) {
        // Invoke insertFront for every node
        for(; k>0; --k)
            insertFront(t);
    }

    // Operator < overloading
    bool operator <(const dList& d) const {
        // Invoke isLess
        return isLess(first, d.first);
    }

    // Cool iteration or something (idk I'm not studying CS)
    class const_iterator {
    friend class dList<T>;
    private:
        // Pointer to node
        node* ptr;
        // Past the end bool
        bool pte;
        // node* -> const_iterator conversion
        const_iterator(node* p, bool b =false) : ptr(p), pte(b) {}
    public:
        // Constructor
        const_iterator() : ptr(nullptr), pte(false) {}
        // Operator * overloading
        const T& operator *() const {
            return ptr->info;
        }
        // Operator -> overloading
        const T* operator ->() const {
            return &(ptr->info);
        }
        // Operator ++const_iterator overloading
        const_iterator& operator ++() {
            // Increment first, then return
            // Pointer must exist and pte must be false
            if(ptr && !pte) {
                // If next pointer is null, set past the end
                if(ptr->next == nullptr) {
                    ptr += 1;
                    pte = true;
                }
                // Otherwise "increment" by going to next pointer
                else
                    ptr = ptr->next;
            }
            return *this;
        }
        // Operator const_iterator++ overloading
        const_iterator operator ++(int) {
            // Use aux to return original "value" instead of returning increment
            const_iterator aux(*this);
            if(ptr && !pte) {
                if(ptr->next == nullptr) {
                    ptr += 1;
                    pte = true;
                }
                else
                    ptr = ptr->next;
            }
            return aux;
        }
        // Operator --const_iterator overloading
        const_iterator& operator --() {
            // Pointer must exist
            if(ptr) {
                // If pte is true, go before "past the end"
                if(pte) {
                    ptr -= 1;
                    pte = false;
                }
                // Otherwise "decrement" by going to previous pointer
                else
                    ptr = ptr->prev;
            }
            return *this;
        }
        // Operator const_iterator-- overloading
        const_iterator operator --(int) {
            const_iterator aux(*this);
            if(ptr) {
                if(pte) {
                    ptr -= 1;
                    pte = false;
                }
                else
                    ptr = ptr->prev;
            }
            return aux;
        }
        // Operator == overloading
        bool operator ==(const const_iterator& cit) const {
            // Compare pointers
            return ptr == cit.ptr;
        }
        // Operator != overloading
        bool operator !=(const const_iterator& cit) const {
            // Compare pointers
            return ptr != cit.ptr;
        }
    };

    // Return first node as iterator
    const_iterator begin() const {
        return first;
    }

    // Return last node as iterator
    const_iterator end() const {
        // If first node is null, return empty iterator
        if(first == nullptr)
            return const_iterator(nullptr, false);
        // Otherwise return iterator from last node + 1 position (past the end)
        return const_iterator(last+1, true);
    }
};

#endif