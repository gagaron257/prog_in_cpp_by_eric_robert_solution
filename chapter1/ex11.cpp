/*
 * File: ex11.cpp
 * ------------------------
 * The German mathematician Leibniz (1646–1716) discovered the rather
 * remarkable fact that the mathematical constant π can be computed using the
 * following mathematical relationship:
 * π
 * 4
 * 
 * ≅ 1 – 1/3 + 1/5 – 1/7 + 1/9 – 1/11
 * + . . .
 * The formula to the right of the equal sign represents an infinite series; each
 * fraction represents a term in that series. If you start with 1, subtract one-third,
 * add one-fifth, and so on, for each of the odd integers, you get a number that
 * gets closer and closer to the value of π/4 as you go along.
 * Write a program that calculates an approximation of π consisting of the first
 * 10,000 terms in Leibniz’s series.
 */

#include <iostream>
using namespace std;

double pi_approximation(int num);

int main()
{
  cout << "Enter the number of terms to approximate: ";
  int num{0};
  cin >> num;
  cout << "Approximation of pi is :" << pi_approximation(num) << endl;

  return 0;
}

/*
 * Function: pi_approximation
 * Usage: pi_approximation(num);
 *----------------------------------
 * Returns the approximation of pi to specified number of terms.
 */

double pi_approximation(int num)
{
  double pi{0.0};
  int sign{-1};
 
  for(int count = 1, i = 1; count <= num; count++, i = i + 2)
  {
    sign = (-1) * sign;  
    pi += (sign) * (float(1) / i);
  }

  return (pi * 4);
} 

