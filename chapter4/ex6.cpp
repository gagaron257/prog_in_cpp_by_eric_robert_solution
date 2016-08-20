/*
 * File : ex6.cpp
 * --------------------------------------------------
 * Another useful function in filelib.h is
 * string defaultExtension(string filename, string ext);
 * which adds ext to the end of filename if it doesn’t already have an
 * extension. For example,
 * defaultExtension("Shakespeare", ".txt")
 * would return "Shakespeare.txt" . If filename already has an extension,
 * that name is returned unchanged, so that
 * defaultExtension("library.h", ".cpp")
 * would ignore the specified extension and return "library.h" unchanged. If,
 * however, ext includes a star before the dot, defaultExtension removes
 * any existing extension from filename and adds the new one (minus the star).
 * Thus,
 * defaultExtension("library.h", "*.cpp")
 * would return "library.cpp" . Write the code for defaultExtension so
 * that it behaves as described in this exercise.
 */
#include <iostream>
#include <string>
using namespace std;

string default_ext(string filename, string ext);

int main()
{
  cout << default_ext("shakespear", ".txt") << endl;
  cout << default_ext("shakespear.h", ".txt") << endl;
  cout << default_ext("shakespear.h", "*.txt") << endl;
  return 0;
}

/*
 * Function : default_ext
 * Usage : string p = default_ext(filename, ext);
 * -----------------------------------------------
 * returns the string as per above description.
 */
string default_ext(string filename, string ext)
{
  string s;
  size_t index = filename.rfind('.');
  size_t i_ext = ext.find('*');
  
  if (index == string::npos && i_ext == string::npos)
  {
    s = filename + ext;
  }
  else if(index == string::npos && i_ext != string::npos)
  {
    s = filename + ext.substr(i_ext+1);
  }
  else if(index != string::npos && i_ext != string::npos)
  {
    s = filename.substr(0, index) + ext.substr(i_ext + 1);
  }
  else if(index != string::npos && i_ext == string::npos)
  {
    cerr << "Cannot overwrite the ext, * command not provided";
  }
  else
  {
    cerr << "User error " << endl;
  }
  return s;
}
  
