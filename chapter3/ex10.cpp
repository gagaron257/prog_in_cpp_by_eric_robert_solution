/*
 * File: ex10.cpp
 * ------------------------
 * Write a function
 * string replaceAll(string str, char c1, char c2);
 * that returns a copy of str with every occurrence of c1 replaced by c2 . For
 * example, calling
 * replaceAll("nannies", 'n', 'd');
 * should return "daddies" .
 */

#include <iostream>
#include <string>
using namespace std;

string replace_all(string str, char c1, char c2);
string replace_all(string str, string s1, string s2);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "Enter the c1 to replace :";
  char c1;
  cin >> c1;
  cout << "Enter the c2 to replace with :";
  char c2;
  cin >> c2;
  cout << "The replaced string "
       << replace_all(str, c1, c2) << endl;
  cout << "The replace string "
       << replace_all(str, "abc", "xx") << endl;
  return 0;
}

/*
 * Function: replace_all
 * Usage: string p = replace_all(str, c1, c2)
 * ----------------------------------
 * Returns the new string with all c1 characters
 * replaced with c2.
 */
string replace_all(string str, char c1, char c2)
{
  string s;
  
  for (auto c: str)
  {
    if (c == c1)
      s.push_back(c2);
    else
      s.push_back(c);
  }
  return s;
}

string replace_all(string str, string s1, string s2)
{
  string s;
  decltype(str.length()) start{0};
 
  while (true)
  {
    decltype(str.length()) i = str.find(s1, start);
    if (i != string::npos)
    {
      s += str.substr(start, (i - start));
      s += s2;
      start = (i + s1.length());
    }
    else
    {
      if (start < str.length())
        s += str.substr(start);
      break;
    }
  }
  return s;
}
    
