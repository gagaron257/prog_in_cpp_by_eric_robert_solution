/*
 * File : ex11.cpp
 * ---------------------------------------------------
 * Using the functions stringToInteger and integerToString as a model,
 * write the code necessary to implement stringToReal and realToString .
 */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

double string_to_real(string num);
string real_to_string(double num);

int main()
{
  cout << "Enter the number: ";
  string num;
  cin >> num;
  cout << string_to_real(num) << endl;
  cout << string_to_real(num) / 10 << endl;
  
  cout << "Enter the number: ";
  double n;
  cin >> n;
  cout << real_to_string(n) << endl;
  cout << real_to_string(n) + " i am string" << endl;
  return 0;
}

/*
 * Function : string_to_real
 * Usage : double p = string_to_real(num);
 * --------------------------------------------------
 * Returns the real representation of number from
 * string format.
 */
double string_to_real(string num)
{
  stringstream ss(num);
  double n;
  ss >> n >> ws;
  if (ss.fail() || !ss.eof())
  {
    cerr << "Invalid input format" << endl;
    exit(EXIT_FAILURE);
  }
  return n;
}

/*
 * Function : real_to_string
 * Usage : string s = real_to_string(str);
 * -----------------------------------------------
 * returns the string representation of real number.
 */
string real_to_string(double num)
{
  ostringstream oss;
  oss << num;
  return oss.str();
}
