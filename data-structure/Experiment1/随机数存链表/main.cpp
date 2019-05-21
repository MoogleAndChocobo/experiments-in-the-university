/**
  * C++: list
  *
  * @author MoogleAndChocobo
  * @date 2019/05/08
  */


#include <unistd.h>
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

#include "list.h"
#include "list.cpp"

#define kGenerateNumber 10

using namespace std;

void Format()
{
    cout << "\n------------------------------------------\n\n";
    sleep(1);
}

int main()
{
    List<int> qlist;
    //generate 3-digit integers
    time_t seed;
    srand((unsigned)time(&seed));
    for (int i = 0; i < kGenerateNumber; ++i)
    {
        qlist.Insert(rand()%900+100);
    }


    //Print the list.
    qlist.Print();
    Format();


    //Check an integer is in or not in the list.
    int number = 0;
    cout << "please input an integer "
            "you'd like to check is in or not in the list:";
    cin >> number;
    int number_position = qlist.IsIn(number);
    if(number_position == -1)
    {
        cout << "This integer is not int the list." << endl;
    }
    else
    {
        cout << "This integer is No."
             << number_position+1 << "." << endl;
    }
    Format();


    //Insert an integer into the list and print the list.
    cout << "please input an integer "
            "you'd like to insert into the list:";
    cin >> number;
    qlist.Insert(number);
    cout << "After insert into this integer" << endl;
    qlist.Print();
    Format();


    //Delete an integer and print the list.
    cout << "please input an integer "
            "you'd like to delete from the list:";
    cin >> number;
    if(qlist.Delete(number))
        cout << "The integer is deleted." << endl;
    else
        cout << "The integer in not in the list." << endl;
    qlist.Print();
    Format();

    //Reverse the list and print the list.
    qlist.Reverse();
    cout << "After the reversion" << endl;
    qlist.Print();
    Format();

    return 0;
}
