#ifndef STACK_H
#define STACK_H

#include "node.h"


template <typename T> class Stack
{
private:
    Node<T>* top_;
    int size_;

public:
    Stack<T>();
    void Push(T number);
    T Pop();
    int Size();
};

#endif // STACK_H
