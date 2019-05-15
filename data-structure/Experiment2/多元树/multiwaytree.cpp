#include "multiwaytree.h"
#include "multiwaytreenode.h"

#include <iostream>
#include <vector>
#include <queue>

// constructor: create a root node
template <typename TElemType>
MultiwayTree<TElemType>::MultiwayTree()
{

}


// create a subtree
template <typename TElemType>
void MultiwayTree<TElemType>::CreateTreePreNode(vector<TElemType>& input, MultiwayTreeNode<TElemType>*& tmproot, int& position, int& inputsize)
{
    if(position >= inputsize || input[position] == -1)
    {
        position++;
        return;
    }
    tmproot =  new MultiwayTreeNode<TElemType>();
    tmproot->data_ = input[position++];
    CreateTreePreNode(input, tmproot->firstchild_, position, inputsize);
    CreateTreePreNode(input, tmproot->nextsibling_, position, inputsize);

}


// pre-order traversal
template <typename TElemType>
void MultiwayTree<TElemType>::TraversePre(MultiwayTreeNode<TElemType>*& visit)
{
    if(visit == nullptr)
        return;
    std::cout << visit->data_ << " ";
    TraversePre(visit->firstchild_);
    TraversePre(visit->nextsibling_);
}


// level-order traversal
template <typename TElemType>
void MultiwayTree<TElemType>::TraverseLevel(MultiwayTreeNode<TElemType>*& visit)
{
    if(!visit)
        return;
    queue<MultiwayTreeNode<TElemType>*> nodequeue;

    nodequeue.push(visit);
    while(!nodequeue.empty())
    {
        MultiwayTreeNode<TElemType>* topnode = new MultiwayTreeNode<TElemType>();
        topnode = nodequeue.front();
        nodequeue.pop();    // pop up the first node

        cout << topnode->data_ << " ";

        topnode = topnode->firstchild_;
        if(topnode)
            nodequeue.push(topnode);
        while(topnode)
        {
            topnode = topnode->nextsibling_;
            if(topnode)
                nodequeue.push(topnode);
        }
    }
}


// post-order traversal
template <typename TElemType>
void MultiwayTree<TElemType>::TraversePost(MultiwayTreeNode<TElemType>*& visit)
{
    if (visit == nullptr)
        return;
    TraversePost(visit->firstchild_);
    std::cout << visit->data_ << " ";
    TraversePost(visit->nextsibling_);
}
