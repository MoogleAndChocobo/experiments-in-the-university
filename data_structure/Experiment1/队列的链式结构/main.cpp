#include <unistd.h>
#include <iostream>
#include <cmath>
#include <ctime>

#include "queue.h"
#include "queue.cpp"

#define kGenerateNumber 10

using namespace std;

void Format()
{
    cout << "\n------------------------------------------\n\n";
    sleep(1);
}

int main()
{
    Queue<int> qqueue;
    //generate 3-digit integers
    time_t seed;
    srand((unsigned)time(&seed));
    for (int i = 0; i < kGenerateNumber; ++i)
    {
        int num = rand()%900+100;
        qqueue.Push(num);
    }

    //Print the queue.
    qqueue.Print();
    Format();

    //Reverse the queue and print it.
    qqueue.Reverse();
    int count_number = 0;
    cout << "After reverse the queue" << endl;
    while(qqueue.Size())
    {
        cout << ++count_number << ":\t" << qqueue.Pop() << endl;
    }
    Format();

    return 0;
}
