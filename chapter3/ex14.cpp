/*
 * File: ex14.cpp
 * ------------------------
 * When large numbers are written out on paper, it is traditional—at least in the
 * United States—to use commas to separate the digits into groups of three. For
 * example, the number one million is usually written in the following form:
 * 1,000,000
 * To make it easier for programmers to display numbers in this fashion,
 * implement a function
 * string addCommas(string digits);
 * that takes a string of decimal digits representing a number and returns the
 * string formed by inserting commas at every third position, starting on the
 * right. For example, if you were to execute the main program
 * int main() {
 * while (true) {
 * string digits = getLine("Enter a number: ");
 * if (digits == "") break;
 * cout << addCommas(digits) << endl;
 * }
 * return 0;
 * }
 * your implementation of the addCommas function should be able to produce the
 * following sample run:
 * Enter a number:
 * 17
 * Enter a number:
 * 1,001
 * Enter a number:
 * 12,345,678
 * Enter a number:
 * 999,999,999
 * Enter a number:
 * 17
 * 1001
 * 12345678
 * 999999999
 */

#include <iostream>
#include <string>
using namespace std;

string add_commas(string num);

int main()
{
  while (true)
  {
    cout << "Enter a number : ";
    string num;
    cin >> num;
    if (num == "") break;
    cout << "The digits with commas : "
      << add_commas(num) << endl;
  }
  return 0;
}

/*
 * Function: add_commas
 * Usage: string p = add_commas(num)
 * ----------------------------------
 * Returns the new string with commas added
 * to make US currency representation.
 */
string add_commas(string num)
{
  string s;
  for (int i = num.length() - 1, count = 1; i >= 0; i--)
  {
    if (count <= 3)
    {
      s.push_back(num[i]);
      count++;
    }
    else
    {
      count = 1;
      s.push_back(',');
      s.push_back(num[i]);
      count++;
    }
  }

  string ss;
  for (int i = s.length() - 1; i >= 0; i--)
  {
    ss.push_back(s[i]);
  }
  return ss;
}  
  

    
