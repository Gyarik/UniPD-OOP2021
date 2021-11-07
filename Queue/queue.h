#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

// Queue class incomplete declaration
template <class T> class Queue;
// << overloading incomplete declaration
template <class T> std::ostream& operator <<(std::ostream&, const Queue<T>&);
// QueueItem << overloading incomplete declaration
template <class T> std::ostream& operator <<(std::ostream&, const typename Queue<T>::QueueItem&);

// Queue class
template <class T> class Queue {
private:
    friend std::ostream& operator << <T>(std::ostream&, const Queue&);

    // Single item nested class
    class QueueItem {
    private:
        friend class Queue<T>;
        friend std::ostream& operator << <T>(std::ostream&, const class Queue<T>::QueueItem&);
    public:
        // Constructor
        QueueItem(const T&, QueueItem* =0);
        // Data
        T info;
        // Pointer to next item
        QueueItem* next;
        // Deep item copy
        static QueueItem* copia(QueueItem*);
    };

    // First and last item
    QueueItem* primo;
    QueueItem* ultimo;

    // Auxiliary function for output << overloading
    static std::ostream& print_os(std::ostream&, QueueItem*);

public:
    // Constructors
    Queue();
    Queue(const Queue&);
    // Queue emptiness check
    bool empty() const;
    // Adds item to queue
    void add(const T&);
    // Removes item from queue
    T remove();
    // Destructor
    ~Queue();
    // Operator = overloading
    Queue& operator =(const Queue&);
};

// QueueItem constructor
template <class T> Queue<T>::QueueItem::QueueItem(const T& val, QueueItem* q): info(val), next(q) {}

// Deep item copy
template <class T> class Queue<T>::QueueItem* Queue<T>::QueueItem::copia(Queue<T>::QueueItem* q) {
    // If item is null, return null
    if (q == nullptr){
        return nullptr;
    }
    // Otherwise recursively copy all the items
    return new QueueItem(q->info, copia(q->next));
}

template <class T> std::ostream& Queue<T>::print_os(std::ostream& os, typename Queue<T>::QueueItem* q) {
    // If item is null, return ostream as is
    if(q == nullptr)
        return os;
    // Otherwise put data on ostream, then recursively call function for next item
    os << q->info << ' ';
    return print_os(os, q->next);
}

// Queue default constructor
template <class T> Queue<T>::Queue() : primo(0), ultimo(0) {}

// Queue copy constructor
template <class T> Queue<T>::Queue(const Queue& q) : ultimo(nullptr), primo(Queue<T>::QueueItem::copia(q.primo)) {}

template <class T> bool Queue<T>::empty() const {
    // Simple bool check
    return (primo == 0);
}

template <class T> void Queue<T>::add(const T& val) {
    // If queue is empty, define a new item for both first and last place
    if(empty())
        primo = ultimo = new QueueItem(val);
    // Otherwise add to end of queue
    else {
        ultimo->next = new QueueItem(val);
        ultimo = ultimo->next;
    }
}

template <class T> T Queue<T>::remove() {
    if(empty()) {
        // BAD PRACTICE, will improve later
        std::cerr << "remove() on empty queue" << std::endl;
        exit(1);
    }
    // If queue is not empty, delete first place in the queue and return removed value of item
    QueueItem* p = primo;
    primo = primo->next;
    T aux = p->info;
    delete p;
    return aux;
}

template <class T> Queue<T>::~Queue() {
    // Deep destruction
    while(!empty())
        remove();
}

template <class T> Queue<T>& Queue<T>::operator =(const Queue<T>& q) {
    // Invoked object destruction, then deep copy
    if(this != &q) {
        while(!empty())
            remove();
        primo = Queue<T>::QueueItem::copia(q.primo);
    }
    return *this;
}

template <class T> std::ostream& operator <<(std::ostream& os, const Queue<T>& q) {
    return Queue<T>::print_os(os, q.primo);
}

#endif