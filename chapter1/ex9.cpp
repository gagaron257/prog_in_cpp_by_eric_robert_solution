/*
 * File: ex9.cpp
 * ------------------------
 * Every positive integer greater than 1 can be expressed as a product of prime
 * numbers. This factorization is unique and is called the prime factorization.
 * For example, the number 60 can be decomposed into the factors 2 x 2 x 3 x 5,
 * each of which is prime. Note that the same prime can appear more than once in
 * the factorization.
 * Write a program to display the prime factorization of a number n.
 */

#include <iostream>
using namespace std;

void print_prime_fact(long num);

int main()
{
  cout << "This program factors the number." << endl;
  cout << "Enter the number to factored : ";
  long num{0};
  cin >> num;
  print_prime_fact(num);

  return 0;
}

/*
 * Function: print_prime_fact
 * Usage: print_prime_fact(num);
 *----------------------------------
 * Prints the prime factorization of the given number..
 */

void print_prime_fact(long num)
{
  int n{2};
  
  while (num % n == 0)
  {
    cout << n << " x ";
    num /= n;
  }
  n++;
  while (num != 1)
  {
    while (num % n == 0)
    {
      cout << n << " x ";
      num /= n;
    }
    n += 2;
  }
  cout << "\b\b\b" << "  " << endl;
}

