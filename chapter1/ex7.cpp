/*
 * File: ex7.cpp
 * ------------------------
 * Using the AddIntegerList program from Figure 1-5 as a model, write a
 * program AverageList that reads in a list of integers representing exam scores
 * and then prints out the average. Because some unprepared student might
 * actually get a score of 0, your program should use −1 as the sentinel to mark the
 * end of the input.
 */

#include <iostream>
using namespace std;

const int SENTINAL = -1;

int main()
{
  cout << "This program finds the average of the list of integers." << endl;
  cout << "Enter -1 to signal the end of the list" << endl;
  
  int sum{0};
  int count{0};
 
  while (true)
  {
    int num{0};
    cout << "? ";
    cin >> num;
    if (num == -1) break;
    sum += num;
    count++;
  }

  cout << "The average of the integers " << (sum / count) << endl;  

  return 0;
}

