/*
 * File : ex7.cpp
 * --------------------------------------------
 * On occasion, publishers find it useful to evaluate layouts and stylistic designs
 * without being distracted by the actual words. To do so, they sometimes
 * typeset sample pages in such a way that all of the original letters are replaced
 * with random letters. The resulting text has the spacing and punctuation
 * structure of the original, but no longer conveys any meaning that might get in
 * the way of the design. The publishing term for text that has been replaced in
 * this way is greek, presumably after the old saying “It’s all Greek to me,”
 * which is itself adapted from a line from Julius Caesar.
 * Write a program that reads characters from an input file and displays them
 * on the console after making the appropriate random substitutions. Your
 * program should replace every uppercase character in the input by a random
 * uppercase character and every lowercase character by a random lowercase
 * one. Nonalphabetic characters should remain unchanged. For example, if the
 * input file Troilus.txt contains the text from Troilus and Cressida,
 * Troilus.txt
 * Ay, Greek; and that shall be divulged well
 * In characters as red as Mars his heart
 * Inflamed with Venus:
 * your program should generate output that looks something like this:
 * Greek
 * Input file: Troilus.txt
 * Ne, Inyes; fmd ckhj zntqt uv dqijxnkp uyww
 * Rt pkjfvkmzdf yt kut ya Itgp byi blxod
 * Ogmgmkwl jjbe Nscku:
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int random_int(int low, int high);

int main()
{
 cout << "Enter the filename: " << endl;
 string file;
 cin >> file;
 
 ifstream infile;
 infile.open(file.c_str());
 if (infile.fail())
 {
   cerr << "ERROR: file operation failure" << endl;
   exit(EXIT_FAILURE);
 }
 
 srand(time(NULL));
 char c;
 while ((c = infile.get()) != EOF)
 {
   if (isalpha(c))
   {
     if (isupper(c))
       cout << char(random_int(65, 90));
     else
       cout << char(random_int(97, 122));
   }
   else
     cout << c;
 }
 return 0;    
}

/*
 * Function : random_int
 * Usage : int p = random_int(low, high);
 * ------------------------------------------
 * Returns the random integer in range of 
 * low to high.
 */
int random_int(int low, int high)
{
  return int ((rand()/(float(RAND_MAX) + 1)) * (high - low) + low);
}
