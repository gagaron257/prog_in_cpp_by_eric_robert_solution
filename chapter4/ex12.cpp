/*
 * File : ex12.cpp
 * ----------------------------------
 * Complete the implementation of the simpio.h interface by implementing the
 * functions getReal and getLine .
 */
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

double get_real(string prompt = "> ");
string get_line(string prompt = "> ");

int main()
{
  double num = get_real("Enter the real number: ");
  cout << num << endl;
  string s = get_line("Enter the line: ");
  cout << s << endl;
  return 0;
}

/*
 * Function : get_real
 * Usage : double p = get_real("Enter the number: ");
 * --------------------------------------------------
 * Return the real number from userinput.
 */
double get_real(string prompt)
{
  double num;
  string in;
  while (true)
  {
    cout << prompt ;
    getline(cin, in);
    istringstream instream(in);
    instream >> num >> ws;
    if (!instream.fail() || instream.eof())
      break;
    cerr << "Invalid input.Try again" << endl;
  }
  return num;
}

/*
 * Function : get_line
 * Usage : string p = get_line("Enter the string:");
 * ---------------------------------------------------
 * returns the line enter by the user.
 */
string get_line(string prompt)
{
  string s;
  cout << prompt;
  getline(cin, s);
  return s;
}
