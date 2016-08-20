/*
 * File: ex9.cpp
 * ------------------------
 * The waste of time in spelling imaginary sounds and their history
 * (or etymology as it is called) is monstrous in English . . .
 * —George Bernard Shaw, 1941
 * In the early part of the 20 th century, there was considerable interest in both
 * England and the United States in simplifying the rules used for spelling
 * English words, which has always been a difficult proposition. One suggestion
 * advanced as part of this movement was to eliminate all doubled letters, so that
 * bookkeeper would be written as bokeper and committee would become comite.
 * Write a function removeDoubledLetters(str) that returns a new string in
 * which any duplicated characters in str have been replaced by a single copy.
 */

#include <iostream>
#include <string>
using namespace std;

string remove_doubled_letters(string str);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "The double letter removal string "
       << remove_doubled_letters(str) << endl;
  return 0;
}

/*
 * Function: remove_doubled_letters
 * Usage: string p = remove_doubled_letters(str)
 * ----------------------------------
 * returns the new string with consecutive letters 
 * removed by single instance.
 */
string remove_doubled_letters(string str)
{
  string s;
  char prev = '\0';

  for(auto c: str)
  {
    if (c != prev)
    {
      s.push_back(c);
      prev = c;
    }
  }
  return s;
}


