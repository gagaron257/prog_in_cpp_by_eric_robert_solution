/*
 * File : ex3.cpp
 * -------------------------------------------
 * Write a program that prints out the longest line in a file entered by the user. If
 * several lines are all equally long, your program should print out the first such
 * line.
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
  ifstream infile;
  cout << "Enter the filename: ";
  string filename;
  getline(cin, filename);
  infile.open(filename.c_str());

  if (infile.fail())
  {
    cerr << "ERROR: In file operation " << endl;
    exit(EXIT_FAILURE);
  }
  string s;
  string max;
  while (getline(infile, s))
  {
    if (s.length() > max.length())
      max = s;
  }
  infile.close();
  cout << "Max line : " << max << endl;
  return 0;
}
