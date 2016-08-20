/*
 * File: ex6.cpp
 * ------------------------
 *  write a program that finds both the
 *  largest and the second-largest number in a list, prior to the entry of a sentinel.
 *  Once again using 0 as the sentinel.
 */

#include <iostream>
using namespace std;

const int SENTINAL = 0;

int main()
{
  cout << "This program finds the largest integer in the list." << endl;
  cout << "Enter 0 to signal the end of the list" << endl;
  
  int max{0}; 
  int max2{0};
 
  while (true)
  {
    int num{0};
    cout << "? ";
    cin >> num;
    if (num == 0) break;
    if (num > max)
    {
      max2 = max;
      max = num;
    }
    else if( num == max)
    {
      max = num;
    }
    else
    {
      if (num > max2)
        max2 = num;
    }
  }

  cout << "The largest value was " << max << endl;  
  cout << "The seocnd largest value was " << max2 << endl;  

  return 0;
}

