/*
 * File : ex8.cpp
 * ---------------------------------------------------------------
 * Books were bks and Robin Hood was Rbinhd. Little Goody Two
 * Shoes lost her Os and so did Goldilocks, and the former became a
 * whisper, and the latter sounded like a key jiggled in a lck. It was
 * impossible to read “cockadoodledoo” aloud, and parents gave up
 * reading to their children, and some gave up reading altogether. . . .
 * —James Thurber, The Wonderful O, 1957
 * In James Thurber’s children’s story The Wonderful O, the island of Ooroo is
 * invaded by pirates who set out to banish the letter O from the alphabet. Such
 * censorship would be much easier with modern technology. Write a program
 * that asks the user for an input file, an output file, and a string of letters to be
 * eliminated. The program should then copy the input file to the output file,
 * deleting any of the letters that appear in the string of censored letters, no
 * matter whether they appear in uppercase or lowercase form.
 * As an example, suppose that you have a file containing the first few lines
 * of Thurber’s novel, as follows:
 * TheWonderfulO.txt
 * Somewhere a ponderous tower clock slowly
 * dropped a dozen strokes into the gloom.
 * Storm clouds rode low along the horizon,
 * and no moon shown. Only a melancholy
 * chorus of frogs broke the soundlessness.
 * If you run your program with the input
 * BanishLetters
 * Input file: TheWonderfulO.txt
 * Output file: TheWnderful.txt
 * Letters to banish: o
 * it should write the following file:
 * TheWnderful.txt
 * Smewhere a pnderus twer clck slwly
 * drpped a dzen strkes int the glm.
 * Strm cluds rde lw alng the hrizn,
 * and n mn shwn. nly a melanchly
 * chrus f frgs brke the sundlessness.
 * If you tried to get greedy and banish all the vowels by entering aeiou in
 * response to the prompt, the contents of the output file would be
 * Smwhr pndrs twr clck slwly
 * drppd dzn strks nt th glm.
 * Strm clds rd lw lng th hrzn,
 * nd n mn shwn. nly mlnchly
 * chrs f frgs brk th sndlssnss.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
  cout << "Enter the string to banish: ";
  string bann;
  cin >> bann;
  
  cout << "Enter the file name: ";
  string file;
  cin >> file;
  ifstream infile(file.c_str());
  if (infile.fail())
  {
    cerr << "ERROR: in file operation" << endl;
    exit(EXIT_FAILURE);
  }
  
  ofstream outfile("banish.txt");

  char c;
  while((c = infile.get()) != EOF)
  {
      if (bann.find(c) == string::npos)
        outfile << c;
  }
  outfile.close();
  infile.close();
  return 0;
}
