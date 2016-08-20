/*
 * File: ex5.cpp
 * ------------------------
 * In most word games, each letter in a word is scored according to its point
 * value, which is inversely proportional to its frequency in English words. In
 * ScrabbleTM, the points are allocated as follows:
 * Points
 * 1
 * 2
 * 3
 * 4
 * 5
 * 8
 * 10
 * Letters
 * A, E, I, L, N, O, R, S, T, U
 * D, G
 * B, C, M, P
 * F, H, V, W, Y
 * K
 * J, X
 * Q, Z
 * For example, the word "FARM" is worth 9 points in Scrabble: 4 for the F, 1
 * each for the A and the R, and 3 for the M. Write a program that reads in words
 * and prints out their score in Scrabble, not counting any of the other bonuses
 * that occur in the game. You should ignore any characters other than uppercase
 * letters in computing the score. In particular, lowercase letters are assumed to
 * represent blank tiles, which can stand for any letter but have a score of 0.
 */

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int scrabble_score(string str);
int get_score(char c);

int main()
{
  cout << "Enter a string : ";
  string str;
  cin >> str;
  cout << "The " << str << " scrabble_score "  
       << scrabble_score(str) << endl;
  return 0;
}

/*
 * Function: scrabble_score
 * Usage: int p = scrabble_score(str)
 * ----------------------------------
 * Returns the total scrabble score. 
 */
int scrabble_score(string str)
{
  decltype(str.length()) i{0};
  int score{0};
  
  while (i < str.length())
  {
    if(isalpha(str[i]) && isupper(str[i]))
       score += get_score(str[i]);
    i++;
  }
  return score;
}

/*
 * Function : get_score
 * Usage : int p = get_score(c)
 * -----------------------------------
 * returns the score corresponding to given 
 * letter.
 */
int get_score(char c)
{
  switch(c)
  {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      return 1;
    case 'D':
    case 'G':
      return 2;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
      return 3;
    case 'F':
    case 'H':
    case 'W':
    case 'V':
    case 'Y':
      return 4;
    case 'K':
      return 5;
    case 'J':
    case 'X':
      return 8;
    case 'Q':
    case 'Z':
      return 10;
    default:
      return -1;
  }
}
