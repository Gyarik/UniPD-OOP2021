#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

// Single item class
template <class T> class QueueItem {
public:
    // Constructor
    QueueItem(const T&, QueueItem* =0);
    // Data
    T info;
    // Pointer to next item (?)
    QueueItem* next;
    // TO DO
    // QueueItem* copia(QueueItem);
};

template <class T> QueueItem<T>::QueueItem(const T& val, QueueItem* i) : info(val), next(i) {}

// TO DO
// template <class T> QueueItem<T>* QueueItem<T>::copia(QueueItem i) {
//     if(!i)
//         return 0;
//     else
//         return new QueueItem(i->info, copia(i->next));
// }

// Queue class
template <class T> class Queue {
private:
    // First and last item
    QueueItem<T>* primo;
    QueueItem<T>* ultimo;
public:
    // Constructor
    Queue();
    // Queue emptiness checl
    bool empty() const;
    // Adds item to queue
    void add(const T&);
    // Removes item from queue
    T remove();
    // Destructor
    ~Queue();
    // TO DO
    // Queue(const Queue&);
    // Queue& operator =(const Queue&);
};

// Default constructor
template <class T> Queue<T>::Queue() : primo(0), ultimo(0) {}

template <class T> bool Queue<T>::empty() const {
    // Simple bool check
    return (primo == 0);
}

template <class T> void Queue<T>::add(const T& val) {
    // If queue is empty, define a new item for both first and last place
    if(empty())
        primo = ultimo = new QueueItem<T>(val);
    // Otherwise add to end of queue
    else {
        ultimo->next = new QueueItem<T>(val);
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
    QueueItem<T>* p = primo;
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

// TO DO
// template <class T> Queue<T>::Queue(const Queue& q) : primo(QueueItem<T>::copia(q.primo)) {
//     QueueItem<T>* aux = primo;
//     while(aux != nullptr) {
//         ultimo = aux;
//         aux = aux->next;
//     }
// }

// TO DO
// template <class T> typename Queue<T>::Queue& Queue<T>::operator =(const Queue& q) {}

#endif