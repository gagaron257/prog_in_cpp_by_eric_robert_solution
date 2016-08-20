/*
 * File: ex8.cpp
 * ------------------------
 * Although Euclid’s algorithm for calculating the greatest common divisor is one
 * of the oldest to be dignified with that term, there are other algorithms that date
 * back many centuries. In the Middle Ages, one of the problems that required
 * sophisticated algorithmic thinking was determining the date of Easter, which
 * falls on the first Sunday after the first full moon following the vernal equinox.
 * Given this definition, the calculation involves interacting cycles of the day of
 * the week, the orbit of the moon, and the passage of the sun through the zodiac.
 * Early algorithms for solving this problem date back to the third century and are
 * fully described in the writings of the eighth-century scholar now known as the
 * Venerable Bede.
 * In 1800, the German mathematician Carl Friedrich Gauss published an
 * algorithm for determining the date of Easter that was purely computational in
 * the sense that it relied on arithmetic rather than looking up values in tables. His
 * algorithm—translated directly from the German
 * F I G U R E 2 - 1 8 Gauss’s algorithm for computing the date of Easter
 * I.
 * Divide the number of the year for which one wishes to calculate Easter by 19, by 4, and by 7,
 * and call the remainders of these divisions a, b, and c, respectively. If the division is even, set
 * the remainder to 0; the quotients are not taken into account. Precisely the same is true of the
 * following divisions.
 * II. Divide the value 19a + 23 by 30 and call the remainder d.
 * III. Finally, divide 2b + 4c + 6d + 3, or 2b + 4c + 6d + 4, choosing the former for years between
 * 1700 and 1799 and the latter for years between 1800 and 1899, by 7 and call the remainder e.
 * Then Easter falls on March 22 + d + e, or when d + e is greater than 9, on April d + e – 9.
 * Write a procedure
 * void findEaster(int year, string & month, int & day);
 * that takes a year and returns the Easter date in the reference parameters month
 * and day .
 * Unfortunately, the simple algorithm in Figure 2-15 only works for years in
 * the 18 th and 19 th centuries. It is easy, however, to search the web for extensions
 * that work for all years. Once you have coded and tested your implementation
 * of Gauss’s original algorithm, undertake the necessary research to find a more
 * general approach. 
 */

#include <iostream>
#include <cmath>
using namespace std;

void find_easter(int year, string & month, int & date);

int main()
{
  cout << "Enter the year between 1700 and 1900: ";
  int year;
  cin >> year;
  string month;
  int date;
  find_easter(year, month, date);
  cout << "The easter day is: " << month << " " << date << endl;
  return 0;
}

/*
 * Function : find_easter
 * Usage    : find_easter(year, month, date);
 * ---------------------------------------------
 * returns the month and date of Easter for the year 
 * between 1700 and 1900.
 */
void find_easter(int year, string & month, int & day)
{
  int a = year % 19;
  int b = year % 4;
  int c = year % 7;
  int d = (19 * a + 23) % 30;
  int e = 0;

  if (year >= 1700 && year < 1800)
    e = (2*b + 4*c + 6*d + 3) % 7;
  else if (year >= 1800 && year < 1900)
    e = (2*b + 4*c + 6*d + 2) % 7;

  if ((d+e) < 9)
  {
    month = "MARCH";
    day = (22 + d + e);
  }
  else
  {
    month = "APRIL";
    day = (d + e - 9);
  }
} 
