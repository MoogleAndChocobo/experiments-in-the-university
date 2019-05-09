#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"

template <typename T> class Queue
{
private:
    Node<T>* front_;
    Node<T>* tail_;
    int size_;

public:
    Queue();
    void Push(T number);
    T Front();
    T Pop();
    void Print();
    void Reverse();
    int Size();


};

#endif // QUEUE_H
