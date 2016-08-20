/*
 * File: ex12.cpp
 * ------------------------
 * Write a function createRegularPlural(word) that returns the plural of
 * word formed by following these standard English rules:
 * a. If the word ends in s, x, z, ch, or sh, add es to the word.
 * b. If the word ends in a y preceded by a consonant, change the y to ies.
 * c. In all other cases, add just an s.
 * Write a test program and design a set of test cases to verify that your program
 * works.
 */

#include <iostream>
#include <string>
using namespace std;

string create_regular_plural(string str);

int main()
{
  cout << "Enter a string : ";
  string str;
  cin >> str;
  cout << "The word in plural : "
       << create_regular_plural(str) << endl;
  return 0;
}

/*
 * Function: create_regular_plural
 * Usage: string p = create_regular_plural(str)
 * ----------------------------------
 * Returns the string converted into its 
 * plural form.
 */
string create_regular_plural(string str)
{
  size_t len = str.length();
  string s;
  
  if (str[len-1]== 's' ||
      str[len-1]== 'x' ||
      str[len-1]== 'z' ||
      (str[len-1]== 'h' && 
       (str[len-2]=='c' || str[len-2]=='s')))
     {
       s = str + "es";
     }
  else if (str[len-1] == 'y' &&
           (str[len-1] != 'a' &&
            str[len-1] != 'e' &&
            str[len-1] != 'i' &&
            str[len-1] != 'o' &&
            str[len-1] != 'u'))
    {
      s = str.substr(0, len-1) + "ies";
    }
  else
    {
      s = str + "s";
    }
  return s;
 
}    
