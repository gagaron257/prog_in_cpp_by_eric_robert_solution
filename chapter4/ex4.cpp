/*
 * File : ex4.cpp
 * -----------------------------------------------------------
 * Write a program that reads a file and reports how many lines, words, and
 * characters appear in it. For the purposes of this program, a word consists of a
 * consecutive sequence of any characters except whitespace characters. As an
 * example, suppose that the file Lear.txt contains the following passage from
 * Shakespeare’s King Lear,
 * Lear.txt
 * Poor naked wretches, wheresoe'er you are,
 * That bide the pelting of this pitiless storm,
 * How shall your houseless heads and unfed sides,
 * Your loop'd and window'd raggedness, defend you
 * From seasons such as these? O, I have ta'en
 * Too little care of this!
 * your program should be able to generate the following sample run:
 * FileCounts
 * Input file: Lear.txt
 * Chars: 254
 * Words: 43
 * Lines:
 * 6
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int word_count(istream & in);
int line_count(istream & in);
int char_count(istream & in);

int main()
{
  ifstream infile;
  cout << "Enter the file name: ";
  string filename;
  getline(cin, filename);
  infile.open(filename.c_str());
  if (infile.fail())
  {
    cerr << "ERROR: file operation failure" << endl;
    exit(EXIT_FAILURE);
  }
  
  cout << "The char count : " << char_count(infile) << endl;
  infile.clear();
  infile.seekg(0, ios::beg);
  cout << "The line count : " << line_count(infile) << endl;
  infile.clear();
  infile.seekg(0, ios::beg);
  cout << "The word count : " << word_count(infile) << endl;
  infile.close();
  return 0;
}

/*
 * Function : char_count
 * Usage : int p = char_count(infile);
 * --------------------------------------------
 * Returns the total number of characters both 
 * visible and invisible.
 */
int char_count(istream & in)
{
  int count{0};
  char c;
  while ((c = in.get()) != EOF)
  {
    count++;
  }
  return count;
}

/*
 * Function : line_count
 * Usage : int p = line_count(infile);
 * --------------------------------------
 * Returns the number of lines in the file.
 */
int line_count(istream & in)
{
  int count{0};
  char c;
  while ((c = in.get()) != EOF)
  {
    if (c == '\n')
      count++;
  }
  return count;
}

/*
 * Function : word_count
 * Usage : int p = word_count(infile);
 * ---------------------------------------
 * Returns the number of words in the file.
 */
int word_count(istream & in)
{
  int count{0};
  string s;
  while (in >> s)
    count++;
  return count;
}
