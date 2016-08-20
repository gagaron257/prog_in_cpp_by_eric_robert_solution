/*
 * File: ex8.cpp
 * ------------------------
 * Modify your solution to exercise 7 so that, instead of using a function that
 * returns a new string, you define a function removeCharactersInPlace that
 * removes the letters from the string passed as the first argument.
 */

#include <iostream>
#include <string>
using namespace std;

void remove_characters_inplace(string & str, string remove);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "Enter a remove string: ";
  string remove;
  cin >> remove;
  remove_characters_inplace(str, remove);
  cout << "The inplace removal string " << str << endl;
  return 0;
}

/*
 * Function: remove_characters_inplace
 * Usage: string p = remove_characters_inplace(str, remove)
 * ----------------------------------
 * Modifies original string with all the characters 
 * part of remove string, removed from the str.
 */
void remove_characters_inplace(string & str, string remove)
{
  string s;
  for (auto c: str)
  {
    if (remove.find(c) == string::npos)
      s.push_back(c);
  }
  str =  s;
}


