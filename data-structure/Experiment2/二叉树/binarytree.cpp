#include "binarytree.h"
#include "binarytreenode.h"

#include <iostream>
#include <vector>

// constructor: create a root node
template <typename TElemType>
BinaryTree<TElemType>::BinaryTree()
{
    root_ = new BinaryTreeNode<TElemType>();
    root_->lchild_ = nullptr;
    root_->rchild_ = nullptr;
}


// create a subtree
template <typename TElemType>
void BinaryTree<TElemType>::CreateTreePreNode(vector<TElemType>& input, BinaryTreeNode<TElemType>*& tmproot, int& position, int& inputsize)
{
    tmproot->data_ = input[position++];
    if(tmproot->data_ == -1)
        return;
    if(position < inputsize)
    {
        if(input[position] == -1)
            ++position;
        else
        {
            tmproot->lchild_ = new BinaryTreeNode<TElemType>();
            CreateTreePreNode(input, tmproot->lchild_, position, inputsize);
        }

    }
    if(position < inputsize)
    {
        if(input[position] == -1)
            ++position;
        else
        {
            tmproot->rchild_ = new BinaryTreeNode<TElemType>();
            CreateTreePreNode(input, tmproot->rchild_, position, inputsize);
        }
    }
}

// pre-order traversal
template <typename TElemType>
void BinaryTree<TElemType>::TraversePre(BinaryTreeNode<TElemType>*& visit)
{
    if(visit == nullptr)
        return;
    std::cout << visit->data_ << " ";
    TraversePre(visit->lchild_);
    TraversePre(visit->rchild_);
}


// in-order traversal
template <typename TElemType>
void BinaryTree<TElemType>::TraverseIn(BinaryTreeNode<TElemType>*& visit)
{
    if(visit == nullptr)
        return;
    TraverseIn(visit->lchild_);
    std::cout << visit->data_ << " ";
    TraverseIn(visit->rchild_);

}


// post-order traversal
template <typename TElemType>
void BinaryTree<TElemType>::TraversePost(BinaryTreeNode<TElemType>*& visit)
{
    if (visit == nullptr)
        return;
    TraversePost(visit->lchild_);
    TraversePost(visit->rchild_);
    std::cout << visit->data_ << " ";
}


// remove a subtree
template <typename TElemType>
void BinaryTree<TElemType>::RemoveTree(BinaryTreeNode<TElemType>*& visit)
{
    if(!visit)
        return;
    RemoveTree(visit->lchild_);
    RemoveTree(visit->rchild_);
    delete visit;
}


// delete this tree
template <typename TElemType>
BinaryTree<TElemType>::~BinaryTree()
{
    RemoveTree(root_);
}
