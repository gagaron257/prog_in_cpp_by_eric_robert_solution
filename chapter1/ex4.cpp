/*
 * File: ex4.cpp
 * ------------------------
 *  Write a program that reads in a positive integer N and then calculates and
 *  displays the sum of the first N odd integers. For example, if N is 4, your
 *  program should display the value 16, which is 1 + 3 + 5 + 7.
 */

#include <iostream>
using namespace std;

long sum_of_odd_integers(const int num);

int main()
{
  cout << "Enter the positive integer: ";
  int num{0};
  cin >> num;

  cout << "The sum of first " << num 
       << " odd integers is  " << sum_of_odd_integers(num) << endl;

  return 0;
}

/*
 * Function: sum_of_odd_integers
 * Usage: sum_of_odd_integers(num);
 * ----------------------------------
 * Returns the sum of first 'num' number of odd integers.
 */
long sum_of_odd_integers(const int num)
{
  int sum{0};
  for (int i = 1, count = 1; count <= num; i = i + 2, count++)
  {
    sum += i;
  }
  return sum;
}
