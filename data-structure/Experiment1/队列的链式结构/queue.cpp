#include <iostream>
#include <vector>

#include "queue.h"

using namespace std;

template <typename T>
Queue<T>::Queue()
{
    front_ = new Node<T>();
    tail_ = new Node<T>();
    front_->next_ = tail_;
    size_ = 0;
}

template <typename T>
void Queue<T>::Push(T number)
{
    Node<T>* tmp_node = new Node<T>();
    tail_->data_ = number;
    tail_->next_ = tmp_node;
    tail_ = tmp_node;
    ++size_;
}

template <typename T>
T Queue<T>::Front()
{
    if(!size_)
        return 0;
    return front_->next_->data_;
}

template <typename T>
T Queue<T>::Pop()
{
    if(!size_)
        return 0;
    Node<T>* tmp_node = new Node<T>();
    tmp_node = front_->next_;
    T store_data = tmp_node->data_;
    front_->next_ = tmp_node->next_;
    --size_;
    return store_data;
}

template <typename T>
void Queue<T>::Print()
{

    Node<T>* tmp_node = new Node<T>();
    tmp_node = front_->next_;
    cout << ">>> The following is the data of this list" << endl;
    for (int i = 0; i < size_; ++i)
    {
        cout << i+1 << ":\t" << tmp_node->data_ << endl;
        tmp_node = tmp_node->next_;
    }
}

template <typename T>
void Queue<T>::Reverse()
{
    vector<T> store_data;
    int store_size = size_;
    for(int i = 0; i < store_size; ++i)
    {
        T a = Pop();
        store_data.push_back(a);
    }
    for (int i = store_size-1; i >= 0; --i)
    {
        Push(store_data[i]);
    }
}

template <typename T>
int Queue<T>::Size()
{
    return size_;
}
