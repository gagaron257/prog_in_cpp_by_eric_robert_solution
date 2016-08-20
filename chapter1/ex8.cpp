/*
 * File: ex8.cpp
 * ------------------------
 * Using the digitSum function from the section entitled “The while statement”
 * as a model, write a program that reads in an integer and then displays the
 * number that has the same digits in the reverse order. 
 */

#include <iostream>
using namespace std;

long reverse(long num);

int main()
{
  cout << "This program reverses the digit in the integers." << endl;
  cout << "Enter the positive integer : ";
  long num{0};
  cin >> num;
  cout << "The reversed integer is " << reverse(num) << endl;  

  return 0;
}

/*
 * Function: reverse
 * Usage: long p = reverse(num);
 *----------------------------------
 * Returns the integer with digits with reverse.
 */

long reverse(long num)
{
  long n{0};
  while (num != 0)
  {
    n = 10*n + (num % 10);
    num /= 10;
  }
  
  return n;
}
