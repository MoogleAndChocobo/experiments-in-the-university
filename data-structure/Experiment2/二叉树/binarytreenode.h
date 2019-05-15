#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

template <typename TElemType> class BinaryTreeNode
{
public:
    TElemType data_;
    BinaryTreeNode<TElemType>* lchild_; // left child
    BinaryTreeNode<TElemType>* rchild_; // right child


    BinaryTreeNode(TElemType data = 0, BinaryTreeNode<TElemType>* lchild = nullptr, BinaryTreeNode<TElemType>* rchild = nullptr)
        :data_(data), lchild_(lchild), rchild_(rchild){}

};

#endif // BINARYTREENODE_H
