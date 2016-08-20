/*
 * File: ex4.cpp
 * ------------------------
 * Implement a function capitalize(str) that returns a string in which the
 * initial character is capitalized (if it is a letter) and all other letters are converted
 * to lowercase. Characters other than letters are not affected. For example, both
 * capitalize("BOOLEAN") and capitalize("boolean") should return
 * the string "Boolean" .
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string capitalize(string str);

int main()
{
  cout << "Enter a string : ";
  string str;
  cin >> str;
  cout << "The " << str << " capatilize "  
       << " " << capitalize(str) << endl;
  return 0;
}

/*
 * Function: capitalize
 * Usage: bool p = capitalize(str)
 * ----------------------------------
 * Returns the capitalize string with first letter capital,
 * and rest smaller case. 
 */
string capitalize(string str)
{
  string s;
  decltype(str.length()) i{0};

  while (i < str.length())
  {
    if (isalpha(str[i]))
    {
      if (i == 0)
        s.push_back(toupper(str[i]));
      else
        s.push_back(tolower(str[i]));
    }
    else
      s.push_back(str[i]);
    i++;
  }
  return s;
}
  
