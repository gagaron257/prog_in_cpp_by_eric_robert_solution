/*
 * File: ex5.cpp
 * ------------------------
 * Without using the built-in string method substr , implement a free function
 * substr(str, pos, n) that returns the substring of str beginning at position
 * pos and containing at most n characters. Make sure that your function
 * correctly applies the following rules:
 * • If n is missing or greater than the length of the string, the substring should
 * extend through the end of the original string.
 * • If pos is greater than the length of the string, substr should call error
 * with an appropriate message.
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void error(string msg);
namespace userdef
{
 /*
  * Function : substr
  * Usage : string p = userdef::substr(str, pos, n);
  * -------------------------------------------------
  * Returns the substring p starting at pos with length
  * n bytes long.
  */
  
  string substr(string str, int pos, int  n = -1)
  {
    int str_length = str.size();
    if (pos >= str_length)
      error("pos is greater than string length.");
    if ( n == -1 || n > str_length)
      n = str_length;

    string s;
    while (n && (pos < str_length))
    {
      s.push_back(str[pos++]);
      n--;
    }
    return s;
  }
}       

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "The " << str << " substr "  
       << userdef::substr(str, 2, 3) << endl;
  return 0;
}

/*
 * Function: error
 * Usage: error(msg)
 * ----------------------------------
 * prints the error msg and exit the program. 
 */

void error(string msg)
{
  cerr << msg << endl;
  exit(EXIT_FAILURE);
}
