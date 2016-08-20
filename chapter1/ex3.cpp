/*
 * File: ex3.cpp
 * ------------------------
 * As mathematical historians have told the story, the German mathematician Carl
 * Friedrich Gauss (1777-1855) began to show his mathematical talent at a very
 * early age. When he was in elementary school, Gauss was asked by his teacher
 * to compute the sum of the numbers between 1 and 100. Gauss is said to have
 * given the answer instantly: 5050. Write a program that computes the answer to
 * the question Gauss’s teacher posed.
 */

#include <iostream>
using namespace std;

long sum_of_natural_numbers(const int num);

int main()
{
  cout << "Enter the natural number till sum is required: ";
  int num{0};
  cin >> num;

  cout << "The sum of natural number till " << num 
       << " is " << sum_of_natural_numbers(num) << endl;

  return 0;
}

/*
 * Function: sum_of_natural_numbers
 * Usage: sum_of_natural_numbers(num);
 * ----------------------------------
 * Returns the sum of all natural numbers ranging from 1 to num..
 */
long sum_of_natural_numbers(const int num)
{
  int sum{0};
  for (int i = 1; i <= num; i++)
  {
    sum += i;
  }
  return sum;
}
