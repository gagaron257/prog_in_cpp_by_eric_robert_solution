/*
 * File: ex5.cpp
 * ------------------------
 * Write a program that reads in a list of integers from the user until the user
 * enters the value 0 as a sentinel. When the sentinel appears, your program
 * should display the largest value in the list.
 */

#include <iostream>
using namespace std;

const int SENTINAL = 0;

int main()
{
  cout << "This program finds the largest integer in the list." << endl;
  cout << "Enter 0 to signal the end of the list" << endl;
  
  int max{0};  
  while (true)
  {
    int num{0};
    cout << "? ";
    cin >> num;
    if (num == 0) break;
    if (num > max)
      max = num;
  }

  cout << "The largest value was " << max << endl;  

  return 0;
}

