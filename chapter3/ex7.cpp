/*
 * File: ex7.cpp
 * ------------------------
 * Write a function
 * string removeCharacters(string str, string remove);
 * that returns a new string consisting of the characters in str after removing all
 * instances of the characters in remove . For example, if you call
 * removeCharacters("counterrevolutionaries", "aeiou")
 * the function should return "cntrrvltnrs" , which is the original string after
 * removing all of its vowels.
 */

#include <iostream>
#include <string>
using namespace std;

string remove_characters(string str, string remove);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "Enter a remove string: ";
  string remove;
  cin >> remove;
  cout << "The " << str << " after removing char "  
       << remove_characters(str, remove) << endl;
  return 0;
}

/*
 * Function: remove_characters
 * Usage: string p = remove_characters(str, remove)
 * ----------------------------------
 * Returns the new string with all the characters 
 * part of remove string, removed from the str.
 */
string remove_characters(string str, string remove)
{
  string s;
  for (auto c: str)
  {
    if (remove.find(c) == string::npos)
      s.push_back(c);
  }
  return s;
}


