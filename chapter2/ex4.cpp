/*
 * File: ex4.cpp
 * ------------------------
 *  If you are unfortunate enough to be outside in winter weather, you know that
 *  your perception of the cold is dependent on the wind speed as well as the
 *  temperature. The faster the wind blows, the colder you feel. To quantify the
 *  how wind affects temperature perception, the National Weather Service reports
 *  the wind chill, which is illustrated on their website as shown in Figure 2-15. At
 *  the bottom of the figure, you can see that the formula for wind chill is
 *  35.74 + 0.6215 t – 35.75 v 0.16 + 0.4275 t v 0.16
 *  where t is the Fahrenheit temperature and v is the wind speed in miles per hour.
 *  Write a function windChill that takes the values of t and v and returns the
 *  wind chill. In doing so, your function should take account of two special cases:
 *  • If there is no wind, windChill should return the original temperature t.
 *  • If the temperature is greater than 40° F, the wind chill is undefined, and
 *  your function should call error with an appropriate message.
 *  Although it will be easier to do so once you learn how to format numeric
 *  data in Chapter 4, you already know enough to generate a table that presents the
 *  wind-chill data in columns as shown in Figure 2-15. If you’re up for more of a
 *  challenge, write a main program that uses windChill to produce that table.
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

double wind_chill(const double temperature, const double velocity);
void error(string msg);
void print_wind_chill_table(void);


int main()
{
  print_wind_chill_table();
  return 0;
}

/*
 * Function: wind_chill
 * Usage: double chill = wind_chill(t, v)
 * ----------------------------------
 * Returns wind chill is
 * 35.74 + 0.6215 t – 35.75 v 0.16 + 0.4275 t v 0.16
 * where t is the Fahrenheit temperature and v is the wind speed in miles per hour.
 */
double wind_chill(const double t, const double v)
{
  if (t > 40) error("The temperature greater than 40 degree F");
  if (v)
    return (35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) + (0.4275 * t * pow(v, 0.16)));
  else
    return t;    
}

/*
 * Function: error
 * Usage: error(msg)
 * ----------------------------------
 *  This function writes out the error message to the cerr stream and
 *  then exits the program. The EXIT_FAILURE constant is defined in
 *  <cstdlib> to represent a standard failure code.
 * 
 */

void error(string msg)
{
  cerr << msg << endl;
  exit(EXIT_FAILURE);
}

/*
 * Function: print_wind_chill
 * Usage: print_wind_chill()
 * ----------------------------------
 * Prints the formatted output table for the windchill.
 */

void print_wind_chill_table(void )
{
  cout << setw(5) << "Calm|";

  for (int i = 40; i >= -45 ; i = i - 5)
    cout << setw(4) << i ;
  cout << endl;

  for (int i = 1; i <= 80; i++)
    cout << "-" ;
  cout << endl;

  for (int i = 5; i <= 60; i += 5)
  {
    cout << setw(4) << i << "|";
    for (int j = 40; j >= -45; j -= 5)
      cout << setw(4) << int(wind_chill(j, i));
    cout << endl;
  }
  cout << " X axis = Temperature in degree F " << endl;
  cout << " Y axis = wind velocity in mph " << endl;

}
    
