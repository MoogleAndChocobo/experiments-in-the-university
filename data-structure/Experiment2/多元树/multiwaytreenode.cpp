#ifndef MULTIWAYTREENODE_H
#define MULTIWAYTREENODE_H

template <typename TElemType> class MultiwayTreeNode
{
public:
    TElemType data_;
    MultiwayTreeNode<TElemType>* firstchild_; // first child
    MultiwayTreeNode<TElemType>* nextsibling_; // next sibling


    MultiwayTreeNode(TElemType data = 0, MultiwayTreeNode<TElemType>* firstchild = nullptr, MultiwayTreeNode<TElemType>* nextsibling = nullptr)
        :data_(data), firstchild_(firstchild), nextsibling_(nextsibling){}

};

#endif // MULTIWAYTREENODE_H
