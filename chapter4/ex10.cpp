/*
 * File : ex10.cpp
 * ---------------------------------------------------
 * Some files use tab characters to align data into columns. Doing so, however,
 * can cause problems for applications that are unable to work directly with tabs.
 * For these applications, it is useful to have access to a program that replaces
 * tabs in an input file with the number of spaces required to reach the next tab
 * stop. In programming, tab stops are usually set at every eight columns. For
 * example, suppose that the input file contains a line of the form
 * abc
 * pqrst
 * xyz
 * where the
 * symbol represents the space taken up by a tab, which differs
 * depending on its position in the line. If the tab stops are set every eight
 * spaces, the first tab character must be replaced by five spaces and the second
 * tab character by three.
 * Write a program that copies an input file to an output file, replacing all tab
 * characters by the appropriate number of spaces.
 */
#include <iostream>
#include <fstream>
using namespace std;

void remove_tabs_with_space(istream & in, ostream & out);

int main()
{
  cout << "Enter the file name: ";
  string infile;
  getline(cin, infile);
  ifstream in(infile.c_str());
  if (in.fail())
  {
    cerr << "ERROR: invalid file operation" << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Enter the output file name: ";
  string outfile;
  getline(cin, outfile);
  ofstream out(outfile.c_str());
  
  remove_tabs_with_space(in, out);
  in.close();
  out.close();
  return 0;
}

/*
 * Function : remove_tabs_with_space
 * Usage : remove_tabs_with_space(in, out);
 * --------------------------------------------------
 * converts the input file to output file with all 
 * tabs replaced with spaces upto next tab stop.
 */
void remove_tabs_with_space(istream & in, ostream & out)
{
  const int TAB_STOP = 8;
  char c;
  int count{0};

  while ((c = in.get()) != EOF)
  {
    count++;
    cout << c << " " << count << endl;
    if (c == '\t')
    {
      int spaces = TAB_STOP - count + 1;
      while (spaces)
      {
        out << " ";
        spaces--;
      }
      count = 0;
    }
    else if(c == '\n')
    {
      out << c;
      count = 0;
    }
    else
    {
      if (count == TAB_STOP)
        count = 0;
      out << c;
    }

  }
} 
