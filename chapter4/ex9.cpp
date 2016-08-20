/*
 * File : ex9.cpp
 * ---------------------------------------------
 * Even though comments are essential for human readers, the compiler simply
 * ignores them. If you are writing a compiler, you therefore need to be able to
 * recognize and eliminate comments that occur in a source file.
 * Write a function
 * void removeComments(istream & is, ostream & os);
 * that copies characters from the input stream is to the output stream os , except
 * for characters that appear inside C++ comments. Your implementation should
 * recognize both comment conventions:
 *  Any text beginning with 
 */
 /* and ending with */
 /* , possibly many lines later.
  * Any text beginning with // and extending through the end of the line.
  * The real C++ compiler needs to check to make sure that these characters are
  * not contained inside quoted strings, but you should feel free to ignore that
  * detail. The problem is tricky enough as it stands.
  */
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void remove_comments(istream & in, ostream & out);

int main()
{
  ifstream infile("dummy.cpp");
  if (infile.fail())
  {
    cerr << "ERROR in file operation" << endl;
    exit(EXIT_FAILURE);
  }

  ofstream outfile("dummy_comment.cpp");
  if (infile.fail())
  {
    cerr << "ERROR in file operation" << endl;
    exit(EXIT_FAILURE);
  }

  remove_comments(infile, outfile);
  infile.close();
  outfile.close();
  return 0;  
}

/*
 * Function : remove_comments.
 * Usage : remove_comments(in, out);
 * ----------------------------------------
 * remove all the comments from the C or CPP
 * file.
 */
void remove_comments(istream & in, ostream & out)
{
  char c;
  enum State 
  {
    INIT,
    ONE_SLASH,
    TWO_SLASH,
    OPEN_QUOTE,
    SLASH_STAR,
    SLASH_STAR_STAR,
    
  };
  State state = INIT;
  while ((c = in.get()) != EOF)
  {
    switch(state)
    {
      case INIT:
        if (c == '/')
          state = ONE_SLASH;
        else if (c == '"')
        { 
          out << c;
          state = OPEN_QUOTE;
        }
        else
          out << c;
        break;

      case ONE_SLASH:
        if (c == '/')
          state = TWO_SLASH;
        else if(c == '*')
          state = SLASH_STAR;
        else
        {
          out << c;
          state = INIT;
        }
        break;

      case TWO_SLASH:
        if (c == '\n')
          state = INIT;
        break;

      case OPEN_QUOTE:
        if (c == '"')
        {
          state = INIT;
        }
        out << c;
        break;

      case SLASH_STAR:
        if (c == '*')
          state = SLASH_STAR_STAR;
        break;

      case SLASH_STAR_STAR:
        if (c == '/')
          state = INIT;
        else 
          state = SLASH_STAR;
        break;

      default:
        cerr << "DEFAULT error state" << endl;
    }
  }
}
