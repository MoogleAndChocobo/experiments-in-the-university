/**
  * C++: MulttiwayTree
  *
  * @author MoogleAndChocobo
  * @date 2019/05/15
  */


#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include "multiwaytree.h"
#include "multiwaytree.cpp"

int main()
{
    MultiwayTree<int> qmultiwaytree;
    vector<int> input;

    cout << "xxPlease input a tee in pre-order. The input is terminated by \"/\"." << std::endl;
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
    {
        qmultiwaytree.root_ = new MultiwayTreeNode<int>();
        qmultiwaytree.CreateTreePreNode(input, qmultiwaytree.root_, position, inputsize);
    }
    // pre-order traversal
    std::cout << "\nPre-order:" << std::endl;
    qmultiwaytree.TraversePre(qmultiwaytree.root_);

    // level-order traversal
    std::cout << "\nLevel-order:" << std::endl;
    qmultiwaytree.TraverseLevel(qmultiwaytree.root_);

    //post-order traversal
    std::cout << "\nPost-order:" << std::endl;
    qmultiwaytree.TraversePost(qmultiwaytree.root_);
    std::cout << std::endl;
    return 0;
}
