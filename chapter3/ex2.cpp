/*
 * File: ex4.cpp
 * ------------------------
 * The strlib.h function exports a function trim(str) that returns a new
 * string formed by removing all whitespace characters from the beginning and
 * end of str . Write the corresponding implementation.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string trims(string str);

int main()
{
  string str{" gagan  "};
  string trim;
  trim = trims(str);
  cout << "The original :" << str << " the length:" << str.size() << endl;
  cout << "The trimed :" << trim << " the length:" << trim.length() << endl;
  return 0;
}

/*
 * Function: trims
 * Usage: string p = trims(str)
 * ----------------------------------
 * Returns the new string with whitespace trimed from
 * beginning and end.
 */
string trims(string str)
{
  string s = "";
  int i{0};

  while (isspace(str[i]))
    i++;
  while (isalnum(str[i]))
  {
    s.push_back(str[i]);
    i++;
  }

  return s;
}
