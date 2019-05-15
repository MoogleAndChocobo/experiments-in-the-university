#ifndef MULTIWAYTREE_H
#define MULTIWAYTREE_H

#include <vector>

#include "multiwaytreenode.h"

using namespace std;

template <typename TElemType> class MultiwayTree
{
public:
    // constructor: create a root node
    MultiwayTree();

    // create a subtree
    void CreateTreePreNode(vector<TElemType>& input, MultiwayTreeNode<TElemType>*& tmproot, int& postion, int& inputsize);

    // pre-order traversal
    void TraversePre(MultiwayTreeNode<TElemType>*& visit);

    // level-order traversal
    void TraverseLevel(MultiwayTreeNode<TElemType>*& visit);

    // post-order traversal
    void TraversePost(MultiwayTreeNode<TElemType>*& visit);


    MultiwayTreeNode<TElemType>* root_;   // root node

};

#endif // MultiwayTREE_H
