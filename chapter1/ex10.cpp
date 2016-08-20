/*
 * File: ex10.cpp
 * ------------------------
 * In 1979, Douglas Hofstadter, Professor of Cognitive Science at the University
 * of Indiana, wrote Gödel, Escher, Bach, which he described as “a metaphorical
 * fugue on minds and machines in the spirit of Lewis Carroll.” The book won
 * the Pulitzer Prize for Literature and has over the years become one of the
 * classics of computer science. Much of its charm comes from the mathematical
 * oddities and puzzles it contains, many of which can be expressed in the form of
 * computer programs. Of these, one of the most interesting concerns the
 * sequence of numbers formed by repeatedly executing the following rules for
 * some positive integer n:
 * • If n is equal to 1, you’ve reached the end of the sequence and can stop.
 * • If n is even, divide it by two.
 * • If n is odd, multiply it by three and add one.
 * Although it also goes by several other names, this sequence is often called the
 * hailstone sequence because the values tend to go up and down before coming
 * back to 1, much as hailstones do in the clouds in which they form.
 * Write a program that reads in a number from the user and then generates the
 * hailstone sequence from that point.
 */

#include <iostream>
using namespace std;

void print_hailstone_seq(int num);

int main()
{
  cout << "Enter the number : ";
  int num{0};
  cin >> num;
  print_hailstone_seq(num);

  return 0;
}

/*
 * Function: print_hailstone_seq
 * Usage: print_hailstone_seq(num);
 *----------------------------------
 * Prints the hailstone seq for given num.
 */

void print_hailstone_seq(int num)
{
  while (num != 1)
  {
    if (num % 2 == 0)
    {
      cout << num << " is even, so I divided it by 2 to get ";
      num /= 2;
      cout << num << endl;
    }
    else
    {  
      cout << num << " is odd, so I multiply by 3 and add 1 to get ";
      num = num * 3 + 1;
      cout << num << endl;
    }
  }
} 

