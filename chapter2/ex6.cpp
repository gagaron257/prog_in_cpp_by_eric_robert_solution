/*
 * File: ex6.cpp
 * ------------------------
 * An integer greater than 1 is said to be prime if it has no divisors other than
 * itself and one. The number 17, for example, is prime, because there are no
 * numbers other than 1 and 17 that divide evenly into it. The number 91,
 * however, is not prime because it is divisible by 7 and 13. Write a predicate
 * method isPrime(n) that returns true if the integer n is prime, and false
 * otherwise. To test your algorithm, write a main program that lists the prime
 * numbers between 1 and 100.
 */

#include <iostream>
#include <cmath>
using namespace std;

bool is_prime_number(const int num);

int main()
{
  for (int i = 2; i <= 100; i++)
  {
    if (is_prime_number(i))
      cout << i << endl;
  }
  return 0;
}

/*
 * Function: is_prime_number
 * Usage: bool p = is_prime_number(num)
 * ----------------------------------
 * a predicate method is_prime(n) that returns true 
 * if the integer n is prime, and false  otherwise.
 */
bool is_prime_number(const int num)
{
  bool ret_val = true;
  for (int i = 2; i <= int(sqrt(num)); i++)
  {
    if (num % i == 0)
    {
      ret_val = false;
      break;
    }
  }
  return ret_val;
}
