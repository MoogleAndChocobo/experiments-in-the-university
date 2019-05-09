#include <iostream>
#include <vector>

#include "list.h"

using namespace std;

template <typename T>
List<T>::List()
{
    header_ = new Node<T>();
    header_->next_ = nullptr;
}

template <typename T>
void List<T>::Insert(T number)
{
    Node<T>* tmp_node = new Node<T>();
    tmp_node->data_ = number;
    tmp_node->next_ = header_->next_;
    header_->next_ = tmp_node;
}

template<typename T>
int List<T>::IsIn(T number)
{
    Node<T>* tmp_node = new Node<T>();
    tmp_node = header_->next_;
    int count_position = 0;
    while(tmp_node != nullptr)
    {
        if(tmp_node->data_ == number)
        {
            return count_position;
        }
        tmp_node = tmp_node->next_;
        count_position++;
    }
    return -1;
}

template<typename T>
void List<T>::Print()
{
    Node<T>* tmp_node = new Node<T>();
    tmp_node = header_->next_;
    int count_position = 0;
    cout << ">>> The following is the data of this list" << endl;
    while(tmp_node != nullptr)
    {
        cout << count_position+1 << ":\t" << tmp_node->data_ << endl;
        tmp_node = tmp_node->next_;
        ++count_position;
    }
    cout << endl;
    return;
}

template<typename T>
void List<T>::Reverse()
{
    vector<int> store_number;
    store_number.clear();

    Node<T>* tmp_node = new Node<T>();
    tmp_node = header_->next_;
    while(tmp_node != nullptr)
    {
        store_number.push_back(tmp_node->data_);
        tmp_node = tmp_node->next_;
    }

    int position = store_number.size();
    tmp_node = header_->next_;
    while(--position >= 0)
    {
        tmp_node->data_ = store_number[position];
        tmp_node = tmp_node->next_;
    }
}

template<typename T>
bool List<T>::Delete(T number)
{
    Node<T>* tmp_node = new Node<T>();
    Node<T>* pred_node = new Node<T>();
    tmp_node = header_->next_;
    pred_node = header_;
    bool check_delete = false;
    while(tmp_node != nullptr)
    {
        if(tmp_node->data_ == number)
        {
            tmp_node = tmp_node->next_;
            pred_node->next_ = tmp_node;
            check_delete = true;
            continue;
        }
        pred_node = tmp_node;
        tmp_node = tmp_node->next_;
    }
    return check_delete;
}
