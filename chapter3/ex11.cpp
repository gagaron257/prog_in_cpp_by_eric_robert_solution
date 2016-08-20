/*
 * File: ex11.cpp
 * ------------------------
 * The concept of a palindrome is often extended to full sentences by ignoring
 * punctuation and differences in the case of letters. For example, the sentence
 * Madam, I’m Adam.
 * is a sentence palindrome, because if you only look at the letters and ignore any
 * distinction between uppercase and lowercase letters, it reads identically
 * backward and forward.
 * Write a predicate function isSentencePalindrome(str) that returns
 * true if the string str fits this definition of a sentence palindrome. For
 * example, you should be able to use your function to write a main program
 * capable of producing the following sample run:
 * SentencePalindrome
 * This program tests for sentence palindromes.
 * Indicate the end of the input with a blank line.
 * Enter a sentence: Madam, I'm Adam.
 * That sentence is a palindrome.
 * Enter a sentence: A man, a plan, a canal -- Panama!
 * That sentence is a palindrome.
 * Enter a sentence: Not a palindrome.
 * That sentence is not a palindrome.
 * Enter a sentence:
 */

#include <iostream>
#include <string>
using namespace std;

bool is_sentence_palindrome(string str);

int main()
{
  cout << "Enter a string : ";
  string str;
  getline(cin, str);
  cout << "The sentence is palindrome : "
       << is_sentence_palindrome(str) << endl;
  return 0;
}

/*
 * Function: is_sentence_palindrome
 * Usage: bool p = is_sentence_palindrome(str)
 * ----------------------------------
 * Returns true is string is palindrome,
 * otherwise false.
 */
bool is_sentence_palindrome(string str)
{
  for (size_t i = 0, j = str.length() - 1; i <= j; i++, j--)
  {
    while(!isalpha(str[i]))
      i++;
    while(!isalpha(str[j]))
      j--;
    if (str[i] != str[j])
      return false;
  }
  return true;
}    
