/*
 * File: ex12.cpp
 * ------------------------
 * You can also compute π by approximating the area bounded by a circular arc.
 * which has a radius r equal to two inches. From the formula for the area of a
 * circle, you can easily determine that the area of the quarter circle should be π
 * square inches. You can also approximate the area computationally by adding
 * up the areas of a series of rectangles, where each rectangle has a fixed width
 * and the height is chosen so that the circle passes through the midpoint of the top
 * of the rectangle. For example, if you divide the area into 10 rectangles from
 * left to right,
 * The sum of the areas of the rectangles approximates the area of the quarter
 * circle. The more rectangles there are, the closer the approximation.
 * For each rectangle, the width w is a constant derived by dividing the radius
 * by the number of rectangles. The height h, on the other hand, varies depending
 * on the position of the rectangle. If the midpoint of the rectangle in the
 * horizontal direction is given by x, the height of the rectangle can be computed
 * using the sqrt function to express the distance formula
 * h =
 * sqrt(r^2 – x^2)
 * The area of each rectangle is then simply h × w.
 * Write a program to compute the area of the quarter circle by dividing it into
 * 10,000 rectangles. 
 */

#include <iostream>
#include <cmath>
using namespace std;

double approx_area_quater_circle(int num, double radius);

int main()
{
  cout << "Enter the number of terms to approximate: ";
  int num{0};
  cin >> num;
  cout << "Enter the radius of the circle : ";
  double radius{0.0};
  cin >> radius;
  cout << "Approximation of quater circle area with raidus 1 unit is :" 
       << approx_area_quater_circle(num, radius) << endl;

  return 0;
}

/*
 * Function: approx_area_quater_circle
 * Usage: double area = approx_area_quater_circle(num, radius);
 *----------------------------------
 * Returns the approximation of quater circle area
 * with radius 1 unit to specified number rectangles.
 */

double approx_area_quater_circle(int num, double radius)
{
  double area{0.0};
  double width = float(radius) / num;
  double base{0.0};

  for(int count = 1; count <= num; count++)
  {
    base = (count * width) - (width / 2);
    area += width * (sqrt(1.0 - base*base));
  }

  return area;
} 

