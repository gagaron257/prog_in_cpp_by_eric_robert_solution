/*
 * File: ex6.cpp
 * ------------------------
 * An acronym is a new word formed by combining, in order, the initial letters of
 * a series of words. For example, the word scuba is an acronym formed from
 * the first letters in self-contained underwater breathing apparatus. Similarly,
 * AIDS is an acronym for Acquired Immune Deficiency Syndrome. Write a
 * function acronym that takes a string and returns the acronym formed from
 * that string. To ensure that your function treats hyphenated compounds like
 * self-contained as two words, it should define the beginning of a word as any
 * alphabetic character that appears either at the beginning of the string or after a
 * nonalphabetic character.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string acronym(string str);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "The " << str << " acronym "  
       << acronym(str) << endl;
  return 0;
}

/*
 * Function: acronym
 * Usage: string p = acronym(str)
 * ----------------------------------
 * Returns the acronym of the given string.
 */
string acronym(string str)
{
  int start{0};
  string s;

  for (auto c : str)
  {
    if (isalpha(c))
    {
      if (start == 0)
      {
        s.push_back(toupper(c));
        start++;
      }
    }
    else
    { 
      start = 0;
    }
  }
  return s;        
}


