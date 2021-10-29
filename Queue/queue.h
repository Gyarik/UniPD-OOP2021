#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

// DEPRECATED
// Single item class
// template <class T> class QueueItem {
// public:
//     // Constructor
//     QueueItem(const T&, QueueItem* =0);
//     // Data
//     T info;
//     // Pointer to next item (?)
//     QueueItem* next;
//     // TO DO
//     // QueueItem* copia(QueueItem);
// };
// template <class T> QueueItem<T>::QueueItem(const T& val, QueueItem* i) : info(val), next(i) {}

// Queue class incomplete declaration
template <class T> class Queue;
// << overloading incomplete declaration
template <class T> std::ostream& operator <<(std::ostream&, const Queue<T>&);
// QueueItem << overloading incomplete declaration
template <class T> std::ostream& operator <<(std::ostream&, const typename Queue<T>::QueueItem&);

// Queue class
template <class T> class Queue {
private:
    friend std::ostream& operator << <T>(std::ostream&, const Queue<T>&);

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
        // TO DO
        // QueueItem* copia(QueueItem);
    };

    // First and last item
    QueueItem* primo;
    QueueItem* ultimo;
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

// QueueItem constructor
template <class T> Queue<T>::QueueItem::QueueItem(const T& val, QueueItem* q): info(val), next(q) {}

template <class T> std::ostream& operator <<(std::ostream& os, const Queue<T>& q) {
    // TO DO
    return os;
}

template <class T> std::ostream& operator <<(std::ostream& os, const class Queue<T>::QueueItem& q) {
    // TO DO
    return os;
}

// TO DO
// template <class T> class Queue<T>::QueueItem* Queue<T>::QueueItem::copia(QueueItem* q) {
// 	if(!q)
// 		return 0;
// 	else
// 		return new QueueItem(q->info, copia(q->next));
// }

// Queue constructor
template <class T> Queue<T>::Queue() : primo(0), ultimo(0) {}

template <class T> bool Queue<T>::empty() const {
    // Simple bool check
    return (primo == 0);
}

template <class T> void Queue<T>::add(const T& val) {
    // If queue is empty, define a new item for both first and last place
    if(empty())
        primo = ultimo = new Queue<T>::QueueItem(val);
    // Otherwise add to end of queue
    else {
        ultimo->next = new Queue<T>::QueueItem(val);
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
    Queue<T>::QueueItem* p = primo;
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