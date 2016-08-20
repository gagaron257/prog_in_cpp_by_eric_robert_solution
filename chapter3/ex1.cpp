/*
 * File: ex3.cpp
 * ------------------------
 * Implement the function endsWith(str, suffix) , which returns true if
 * str ends with suffix . Like its startsWith counterpart, the endsWith
 * function should allow the second argument to be either a string or a character.
 */

#include <iostream>
#include <string>
using namespace std;

bool ends_with(string str, string suffix);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "Enter the endwith string/char :";
  string suffix;
  getline(cin, suffix);
  cout << "The " << str << " ends with " << suffix 
       << " " << ends_with(str, suffix) << endl;
  return 0;
}

/*
 * Function: ends_with
 * Usage: bool p = ends_with(str, suffix)
 * ----------------------------------
 * Returns false if str does not ends with suffix,
 * otherwise returns true. 
 */
bool ends_with(string str, string suffix)
{
  for (int i = str.size() - 1, j = suffix.size() - 1; j >= 0; i--, j--)
  {
    if (str[i] != suffix[j])
      return false;
  }
  return true;
}
