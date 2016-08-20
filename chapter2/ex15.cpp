/*
 * File: ex15.cpp
 * ------------------------
 *  Heads. . . .
 *  Heads. . . .
 *  Heads. . . .
 *  A weaker man might be moved to re-examine his faith, if in
 *  nothing else at least in the law of probability.
 *  —Tom Stoppard, Rosencrantz and Guildenstern Are Dead, 1967
 *  Write a program that simulates flipping a coin repeatedly and continues until
 *  three consecutive heads are tossed. At that point, your program should display
 *  the total number of coin flips that were made. The following is one possible
 *  sample run of the program:
 *  heads
 *  tails
 *  heads
 *  tails
 *  tails
 *  heads
 *  heads
 *  heads
 *  It took 8 flips to get 3 consecutive heads.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int main()
{
  int count{0};
  int flips{0};

  srand(time(NULL));
  while (count != 3)
  {
    if ((rand()/(double(RAND_MAX)+1)) < 0.5)
    {
      cout << "HEADS" << endl;
      count++;
    }
    else
    {
      cout << "TAILS" << endl;
      count = 0;
    }
    flips++;
  }
  cout << "It took " << flips << " to get three HEADS" << endl;
  return 0;
}


