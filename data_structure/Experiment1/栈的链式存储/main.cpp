#include <iostream>
#include <cmath>
#include <ctime>

#include "stack.h"
#include "stack.cpp"

#define kGenerateNumber 10

using namespace std;

int main()
{
    Stack<int> qstack;
    //generate 3-digit integers
    time_t seed;
    srand((unsigned)time(&seed));
    for (int i = 0; i < kGenerateNumber; ++i)
    {
        qstack.Push(rand()%900+100);
    }
    while(qstack.Size())
    {
        cout << qstack.Pop() << endl;
    }

    return 0;
}
