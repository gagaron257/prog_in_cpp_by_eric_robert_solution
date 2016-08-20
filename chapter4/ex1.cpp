/*
 * File : ex1.cpp
 * -----------------------------------------------
 * The <iomanip> library gives programmers more control over output format,
 * which makes it easy, for example, to create formatted tables. Write a program
 * that displays a table of trigonometric sines and cosines that looks like this:
 * TrigTable
 * theta | sin(theta) | cos(theta) |
 * -------+------------+------------+
 *  -90 | -1.0000000 | 0.0000000 |
 *  -75 | -0.9659258 | 0.2588190 |
 *  -60 | -0.8660254 | 0.5000000 |
 *  -45 | -0.7071068 | 0.7071068 |
 *  -30 | -0.5000000 | 0.8660254 |
 *  -15 | -0.2588190 | 0.9659258 |
 *  0 | 0.0000000 | 1.0000000 |
 *  15 | 0.2588190 | 0.9659258 |
 *  30 | 0.5000000 | 0.8660254 |
 *  45 | 0.7071068 | 0.7071068 |
 *  60 | 0.8660254 | 0.5000000 |
 *  75 | 0.9659258 | 0.2588190 |
 *  90 | 1.0000000 | 0.0000000 |
 *  The numeric columns should all be aligned on the right, and the columns
 *  containing the trigonometric functions (which are listed here for angles in
 *  degrees at 15-degree intervals) should all have seven digits after the decimal
 *  point.
 */  
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void print_sin_cos_table(void);

int main()
{
  print_sin_cos_table();
  return 0;
}

/*
 * Function : print_sin_cos_table
 * Usage : print_sin_cos_table.
 * ----------------------------------------
 * Prints the table in formatted way.
 */
void print_sin_cos_table(void)
{
  const double PI = 3.1415926;
  cout << right;
  cout << fixed;
  cout << setw(8) << " theta |" << setw(13) << " sin(theta) |" << setw(13) << " cos(theta) |" << endl;
  cout << "-------+------------+------------+" << endl;
  for (int i = -90; i <= 90; i += 15)
  {
    double theta = (i * PI)/180;
    cout << setw(7) << i << "|" << setprecision(7) << setw(12) << sin(theta) << "|" << setw(12) << cos(theta)<< "|" << endl;
  }
}
