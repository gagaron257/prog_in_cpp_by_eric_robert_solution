/*
 * File: ex13.cpp
 * ------------------------
 * I shall never believe that God plays dice with the world.
 * —Albert Einstein, 1947
 * Despite Einstein’s metaphysical objections, the current models of physics, and
 * particularly of quantum theory, are based on the idea that nature does indeed
 * involve random processes. A radioactive atom, for example, does not decay for
 * any specific reason that we mortals understand. Instead, that atom has a
 * random probability of decaying within a period of time. Sometimes it does,
 * sometimes it doesn’t, and there is no way to know for sure.
 * Because physicists consider radioactive decay a random process, it is not
 * surprising that random numbers can be used to simulate it. Suppose you start
 * with a collection of atoms, each of which has a certain probability of decaying
 * in any unit of time. You can then approximate the decay process by taking
 * each atom in turn and deciding randomly whether it decays, considering the
 * probability.
 * Write a program that simulates the decay of a sample that contains 10,000
 * atoms of radioactive material, where each atom has a 50 percent chance of
 * decaying in a year. The output of your program should show the number of
 * atoms remaining at the end of each year, which might look something like this:
 * RadioactiveDecay
 * There
 * are
 * 10000 atoms initially.
 * 4957 atoms at the end of year 1.
 * 2484 atoms at the end of year 2.
 * 1215 atoms at the end of year 3.
 * 612 atoms at the end of year 4.
 * 296 atoms at the end of year 5.
 * 143 atoms at the end of year 6.
 * 66 atoms at the end of year 7.
 * 37 atoms at the end of year 8.
 * 15 atoms at the end of year 9.
 * 8 atoms at the end of year 10.
 * 2 atoms at the end of year 11.
 * 0 atoms at the end of year 12.
 * As the numbers indicate, roughly half the atoms in the sample decay each
 * year. In physics, the conventional way to express this observation is to say that
 * the sample has a half-life of one year.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
  cout << "Enter a number of samples: ";
  int samples;
  cin >> samples;

  int decay;
  int year{0};

  cout << "There are " << samples << " initially" << endl;
  while (samples)
  {
    srand(time(NULL));
    decay = 0;
    for (int i = 1; i <= samples; i++)
    { 
      if ((rand()/(double(RAND_MAX) + 1)) <= 0.5)
        decay++;
    }
    samples -= decay;
    year++;
    cout << "There are " << samples << " atoms at the end of year " << year << endl;
  }        

  return 0;
}


