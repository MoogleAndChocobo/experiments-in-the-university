#include "stack.h"

template <typename T>
Stack<T>::Stack()
{
    top_ = new Node<T>();
    top_->next_ = nullptr;
    size_ = 0;
}

template <typename T>
void Stack<T>::Push(T number)
{
    Node<T>* tmp_node = new Node<T>;
    tmp_node->data_ = number;
    tmp_node->next_ = top_;
    top_ = tmp_node;
    ++size_;

}

template <typename T>
T Stack<T>::Pop()
{
    if(!size_)
        return 0;
    Node<T>* tmp_node = top_;
    top_ = top_->next_;
    --size_;
    return tmp_node->data_;

}

template <typename T>
int Stack<T>::Size()
{
    return size_;
}
