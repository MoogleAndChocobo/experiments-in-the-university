#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "binarytree.h"
#include "binarytree.cpp"

int main()
{
    BinaryTree<int> qbinarytree;
    vector<int> input;

    cout << "Please input a tee in pre-order. The input is terminated by \"/\"." << std::endl;
    string signal = "";
    while(std::cin >> signal && signal[0] != '/')
    {
        if(signal == "#")
            input.push_back(-1);
        else
            input.push_back(atoi(signal.c_str()));
    }

    // create a tree
    int inputsize = input.size();
    int position = 0;
    if(inputsize)
        qbinarytree.CreateTreePreNode(input, qbinarytree.root_, position, inputsize);

    // pre-order traversal
    std::cout << "\nPre-order:" << std::endl;
    qbinarytree.TraversePre(qbinarytree.root_);

    // in-order traversal
    std::cout << "\nIn-order:" << std::endl;
    qbinarytree.TraverseIn(qbinarytree.root_);

    //post-order traversal
    std::cout << "\nPost-order:" << std::endl;
    qbinarytree.TraversePost(qbinarytree.root_);
    std::cout << std::endl;
    return 0;
}
