#include <iostream>
#include <string>
using namespace std;

string root(string filename);
string ext(string filename);

int main()
{
  cout << "Enter the filename: ";
  string filename;
  getline(cin, filename);
  cout << "The root: " << root(filename)
       << " The extension: " << ext(filename) << endl;
  return 0;
}

string root(string filename)
{
  size_t index = filename.rfind('.');
  if (index == string::npos)
    return filename;
  else
    return filename.substr(0, index);
}

string ext(string filename)
{
  size_t index = filename.rfind('.');
  if (index == string::npos)
    return "";
  else
    return filename.substr(index+1);
} 
