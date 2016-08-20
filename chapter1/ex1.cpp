/*
 * File: ex1.cpp
 * ------------------------
 * This program reads in a temperature in degrees 
 * Celsius and displays the corresponding temperature 
 * in degrees Fahrenheit.
 */

#include <iostream>
using namespace std;

double celsius_to_fahrenheit(double temp);

int main()
{
  cout << "Enter the temperature in Celsius : ";
  double temp{0.0};
  cin >> temp;
  cout << "The Celsius: " << temp << " to Fahrenheit " 
       << celsius_to_fahrenheit(temp) << endl;

  return 0;
}

/*
 * Function: celsius_to_fahrenheit
 * Usage: double p = celsius_to_fahrenheit(temp);
 * ----------------------------------
 * Returns the temperature in Fahrenheit.
 */
double celsius_to_fahrenheit(double temp)
{
  return ((9 * temp) / 5) + 32;
}
