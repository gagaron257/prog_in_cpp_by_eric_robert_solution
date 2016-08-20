/*
 * File: ex9.cpp
 * ------------------------
 * The combinations function C(n, k) described in this chapter determines the
 * number of ways you can choose k values from a set of n elements, ignoring the
 * order of the elements. If the order of the value matters—so that, in the case of
 * the coin example, choosing a quarter first and then a dime is seen as distinct
 * from choosing a dime and then a quarter—you need to use a different function,
 * which computes the number of permutations. This function is denoted as
 * P(n, k), and has the following mathematical formulation:
 * P(n, k) =
 * n!/(n – k)!
 * Although this definition is mathematically correct, it is not well suited to
 * implementation in practice because the factorials involved can get much too
 * large to store in an integer variable, even when the answer is small. For
 * example, if you tried to use this formula to calculate the number of ways to
 * select two cards from a standard 52-card deck, you would end up trying to
 * evaluate the following fraction:
 * 80,658,175,170,943,878,571,660,636,856,403,766,975,289,505,440,883,277,824,000,000,000,000
 * 30,414,093,201,713,378,043,612,608,166,064,768,844,377,641,568,960,512,000,000,000,000
 * even though the answer is the much more manageable 2652 (52 × 51).
 * Write a function permutations(n, k) that computes the P(n, k) function
 * without calling the fact function. Part of your job in this problem is to figure
 * out how to compute this value efficiently. To do so, you will probably find it
 * useful to play around with some relatively small values to get a sense of how
 * the factorials in the numerator and denominator of the formula behave.
 */

#include <iostream>
using namespace std;

int permutations(int n, int k);

int main()
{
  cout << "Enter a number n and k to find permutation : " << endl;
  int n;
  cin >> n;
  int k;
  cin >> k;
  
  cout << "The permutation is : " 
       << permutations(n, k) << endl;

  return 0;
}

/*
 * Function: permutations
 * Usage: int p = permutations(n, k)
 * -------------------------------------
 * Returns computes the P(n, k) function
 * without calling the fact function.
 */
int permutations(int n, int k)
{
  int val{1};
  
  for(int i = (n-k) + 1; i <= n; i++)
    val = val * i;

  return val;
}
