/*
 * File : ex14.cpp
 * --------------------------------------------------------
 *  Random numbers offer yet another strategy for approximating the value of π.
 *  Imagine that you have a dartboard hanging on your wall that consists of a circle
 *  painted on a square backdrop, as in the following diagram:
 *  What happens if you throw a whole bunch of darts completely randomly,
 *  ignoring any darts that miss the board altogether? Some of the darts will fall
 *  inside the gray circle, but some will be outside the circle in the white corners of
 *  the square. If the darts are random, the ratio of the number of darts landing
 *  inside the circle to the total number of darts hitting the square should be
 *  approximately equal to the ratio between the two areas. The ratio of the areas
 *  is independent of the actual size of the dartboard, as illustrated by the following
 *  formula:
 *  darts falling inside the circle
 *  darts falling inside the square
 *  ≅
 *  area inside the circle
 *  area inside the square
 *  =
 *  π r 2
 *  4 r 2
 *  =
 *  π
 *  4
 *  To simulate this process in a program, imagine that the dart board is drawn
 *  on the standard Cartesian coordinate plane with its center at the origin and a
 *  radius of 1 unit. The process of throwing a dart randomly at the square can be
 *  modeled by generating two random numbers, x and y, each of which lies
 *  between –1 and +1. This (x, y) point always lies somewhere inside the square.
 *  The point (x, y) lies inside the circle if
 *  sqrt (x^ 2 + y^ 2) < 1
 *  This condition, however, can be simplified considerably by squaring each side
 *  of the inequality, which gives the following more efficient test:
 *  x 2 + y 2 < 1
 *  If you perform this simulation many times and compute the fraction of darts
 *  that fall within the circle, the result will be an approximation of π/4.
 *  Write a program that simulates throwing 10,000 darts and then uses the
 *  simulation technique described in this exercise to generate and display an
 *  approximate value of π. Don’t worry if your answer is correct only in the first
 *  few digits. The strategy used in this problem is not particularly accurate, even
 *  though it occasionally proves useful as an approximation technique. In
 *  mathematics, this technique is called Monte Carlo integration, after the capital
 *  city of Monaco.
 */  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

double random_real(double low, double high);

int main()
{
  cout << "Enter the number of darts: ";
  int darts;
  cin >> darts;
  
  srand(time(NULL));
  
  int count_in_circle{0};
  int count_in_square{0};

  for (int i = 1; i <= darts; i++)
  {
    double x_axis = random_real(-1, 1);
    double y_axis = random_real(-1, 1);

    if ((pow(x_axis, 2) + pow(y_axis, 2)) < 1)
    {
      count_in_circle++;
      count_in_square++;
    }
    else
    {
      count_in_square++;
    }
    
  }
  cout << "The value of pi approximately is : " 
       << ((double(count_in_circle) / count_in_square) * 4) << endl;

  return 0;
}

/*
 * Function : random_real
 * Usage : double p = random_real(low, high)
 * ----------------------------------------------
 * Returns the random real integer in range of 
 * low and high values provided as arguments.
 */
double random_real(double low, double high)
{
  return ((rand()/(double(RAND_MAX) + 1)) * (high - low)) - abs(low);
}

