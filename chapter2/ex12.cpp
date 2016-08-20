/*
 * File: ex12.cpp
 * ------------------------
 * Write a program RandomAverage that repeatedly generates a random real
 * number between 0 and 1 and then displays the average after a specified number
 * of trials entered by the user. 
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

double average_random(int num);

int main()
{
  cout << "Enter a number of trails: ";
  int num;
  cin >> num;
  cout << "The average of " << num << " random trails is :" 
       << average_random(num) << endl;

  return 0;
}

/*
 * Function: average_random
 * Usage: double p = average_random(num)
 * ------------------------------------------
 * Returns the average of random numbers in num trials.
 */
double average_random(int num)
{
  srand(time(NULL));
  double sum{0.0};

  for (int i = 1; i <= num; i++)
  {
    sum += (rand()/ (double(RAND_MAX) + 1));
  }
  return (sum / num);  
}
