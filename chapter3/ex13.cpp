/*
 * File: ex13.cpp
 * ------------------------
 * Like most other languages, English include two types of numbers. The
 * cardinal numbers (such as one, two, three, and four) are used in counting; the
 * ordinal numbers (such as first, second, third, and fourth) are used to indicate a
 * position in a sequence. In text, ordinals are usually indicated by writing the
 * digits in the number, followed by the last two letters of the English word that
 * names the corresponding ordinal. Thus, the ordinal numbers first, second,
 * third, and fourth often appear in print as 1st, 2nd, 3rd, and 4th. The ordinals
 * for 11, 12, and 13, however, are 11th, 12th, and 13th. Devise a rule that
 * determines what suffix should be added to each number, and then use this rule
 * to write a function createOrdinalForm(n) that returns the ordinal form of
 * the number n as a string.
 */

#include <iostream>
#include <string>
using namespace std;

string create_ordinal_form(int num);

int main()
{
  cout << "Enter a number : ";
  int num;
  cin >> num;
  cout << "The ordinal form : "
       << create_ordinal_form(num) << endl;
  return 0;
}

/*
 * Function: create_ordinal_form
 * Usage: string p = create_ordinal_form(num)
 * ----------------------------------
 * Returns the string converted into its 
 * ordinal form.
 */
string create_ordinal_form(int num)
{
  string s = to_string(num);

  if (num == 11 || num == 12 || num == 13)
    s += "th";
  else if (num % 10 == 1)
    s += "st";
  else if (num % 10 == 2)
    s += "nd";
  else if (num % 10 == 3)
    s += "rd";
  else
    s += "th";
  
  return s;
}     
  

    
