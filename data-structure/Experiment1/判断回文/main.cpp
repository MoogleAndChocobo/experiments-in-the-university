/**
  * C++: palindrome
  *
  * @author MoogleAndChocobo
  * @date 2019/05/08
  */

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>

#include "stack.h"
#include "stack.cpp"

using namespace std;

int main()
{
    string str;
    cout << "please input a string:";
    cin >> str;

    Stack<char> qstack;
    int str_size = str.size();
    for(int i = 0; i < str_size; ++i)
    {
        qstack.Push(str[i]);
    }
    bool is_palindrome = true;
    for(int i = 0; i < str_size; ++i)
    {
        if(qstack.Pop() != str[i])
        {
            is_palindrome = false;
            break;
        }
    }
    cout << "This is" << (is_palindrome?" ":" not ")
        << "a palindrome." << endl;

    return 0;
}
