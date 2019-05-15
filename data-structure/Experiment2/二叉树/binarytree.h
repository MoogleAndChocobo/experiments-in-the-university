#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>

#include "binarytreenode.h"

using namespace std;

template <typename TElemType> class BinaryTree
{
public:
    // constructor: create a root node
    BinaryTree();

    // delete this tree
    ~BinaryTree();

    // create a subtree
    void CreateTreePreNode(vector<TElemType>& input, BinaryTreeNode<TElemType>*& tmproot, int& postion, int& inputsize);

    // remove a subtree
    void RemoveTree(BinaryTreeNode<TElemType>*& visit);

    // pre-order traversal
    void TraversePre(BinaryTreeNode<TElemType>*& visit);

    // in-order traversal
    void TraverseIn(BinaryTreeNode<TElemType>*& visit);

    // post-order traversal
    void TraversePost(BinaryTreeNode<TElemType>*& visit);


    BinaryTreeNode<TElemType>* root_;   // root node

};

#endif // BINARYTREE_H
