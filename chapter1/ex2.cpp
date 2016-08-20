/*
 * File: ex2.cpp
 * ------------------------
 * This program converts a distance in meters 
 * to the corresponding English distance in feet and inches. 
 * The conversion factors you need are
 * 1 inch = 0.0254 meters
 * 1 foot = 12 inches
 */

#include <iostream>
using namespace std;

void  meters_to_feet_inches(const double distance, int & feet, double & inches);

int main()
{
  cout << "Enter the distance in meters : ";
  double distance{0.0};
  cin >> distance;
  int feet{0};
  double inches{0.0};
  
  meters_to_feet_inches(distance, feet, inches);

  cout << distance << " meters is equal to "  
       << feet << " Feet and " << inches << " inches" << endl;

  return 0;
}

/*
 * Function: meters_to_feet_inches
 * Usage: meters_to_feet_inches(distance, feet, inches);
 * ----------------------------------
 * Returns the feet and inches from distance in meters.
 */
void  meters_to_feet_inches(const double distance, int & feet, double & inches)
{
  inches = distance / 0.0254;
  feet = int (inches / 12);
  inches -= (feet * 12); 
}
