/*
 * File: ex20.cpp
 * ------------------------
 * There is no gene for the human spirit.
 * —Error! Bookmark not defined.Tagline for the 1997 film GATTACA
 * The genetic code for all living organisms is carried in its DNA—a molecule
 * with the remarkable capacity to replicate its own structure. The DNA
 * molecule itself consists of a long strand of chemical bases wound together
 * with a similar strand in a double helix. DNA’s ability to replicate comes from
 * the fact that its four constituent bases—adenosine, cytosine, guanine, and
 * thymine—combine with each other only in the following ways:
 * • Cytosine on one strand links only with guanine on the other, and vice versa.
 * • Adenosine links only with thymine, and vice versa.
 * Biologists abbreviate the names of the bases by writing only the initial letter:
 * A , C , G , or T .
 * Inside the cell, a DNA strand acts as a template to which other DNA
 * strands can attach themselves. As an example, suppose that you have the
 * following DNA strand, in which the position of each base has been numbered
 * as it would be in a C++ string:
 * T A A C G G T A C G T C
 * 0 1 2 3 4 5 6 7 8 9 10 11
 * Your mission in this exercise is to determine where a shorter DNA strand can
 * attach itself to the longer one. If, for example, you were trying to find a match
 * for the strand
 * T
 * T
 * G
 * C
 * C
 * the rules for DNA dictate that this strand can bind to the longer one only at
 * position 1:
 * T T
 * A T
 * A G
 * C C
 * G C
 * G T A C G T C
 * 0 1 2 3 4 5 6 7 8 9 10 11
 * By contrast, the strand
 * T
 * G
 * C
 * matches at either position 2 or position 7.
 * Write a function
 * int findDNAMatch(string s1, string s2, int start = 0);
 * that returns the first position at which the DNA strand s1 can attach to the
 * strand s2 . As in the find method for the string class, the optional start
 * parameter indicates the index position at which the search should start. If
 * there is no match, findDNAMatch should return –1.
 */

#include <iostream>
#include <string>
using namespace std;

int find_DNA_match(string str, string target, int pos = 0);

int main()
{
  cout << "This program finds the matching position for DNA strand" << endl;
  cout << "Enter the DNA string: ";
  string str;
  getline(cin, str);
  cout << "Enter the string to match: ";
  string target;
  cin >> target;
  cout << "Enter the position: ";
  int pos1;
  cin >> pos1;
  cout << "The string matched at "
       << find_DNA_match(str, target, pos1) << endl;
  return 0;
}

/*
 * Function: find_DNA_match 
 * Usage: int p = find_DNA_match(str, target, pos)
 * ----------------------------------
 * Returns the index of the first occurence of match
 * between target string and str string, starting from 
 * position in pos. returns -1 if no match found.
 */
int find_DNA_match(string str, string target, int pos)
{
  for (size_t i = pos; i < str.length(); i++)
  {
    bool match_found = true;
    for (size_t j = 0; j < target.length(); j++)
    {
      if ((str[i+j] == 'T' && target[j] != 'A') ||
          (str[i+j] == 'A' && target[j] != 'T') ||
          (str[i+j] == 'C' && target[j] != 'G') ||
          (str[i+j] == 'G' && target[j] != 'C'))
      {
        match_found = false;
        break;
      }
    }
    if (match_found)
      return i;
  }
  return -1;
}  
  

    
