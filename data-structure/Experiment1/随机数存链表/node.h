#ifndef NODE_H
#define NODE_H


template <typename T> class Node
{
public:
    T data_;
    Node<T>* next_;

    Node<T>(){}
    Node<T>(T e, Node<T>* p = nullptr)
        :data_(e),next_(p){}
};

#endif // NODE_H
