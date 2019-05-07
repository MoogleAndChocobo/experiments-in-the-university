#ifndef LIST_H
#define LIST_H

#include <node.h>

template <typename T> class List
{
private:
    Node<T>* header_;


public:
    List<T>();
    void Insert(T number);
    int IsIn(T number);
    void Print();
    void Reverse();
    bool Delete(T number);
};

#endif // LIST_H
