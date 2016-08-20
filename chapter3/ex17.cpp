/*
 * File: ex17.cpp
 * ------------------------
 * If you played around with codes and ciphers as a child, the odds are good that
 * you at some point used a cyclic cipher—which is often called a Caesar cipher
 * because the Roman historian Suetonius records that Julius Caesar used this
 * technique—in which you replace each letter in the original message by the
 * letter that appears a fixed distance ahead in the alphabet. As an example,
 * suppose that you wanted to encode a message by shifting every letter ahead
 * three places. In this cipher, each A becomes an D, B becomes E, and so on. If
 * you reach the end of the alphabet, the process cycles around to the beginning,
 * so that X becomes A, Y becomes B, and Z becomes C.
 * To implement a Caesar cipher, you should first define a function
 * string encodeCaesarCipher(string str, int shift);
 * that returns a new string formed by shifting every letter in str forward the
 * number of letters indicated by shift , cycling back to the beginning of the
 * alphabet if necessary. After you have implemented encodeCaesarCipher ,
 * write a program that generates the following sample run:
 * CaesarCipher
 * This program encodes a message using a Caesar cipher.
 * Enter the number of character positions to shift: 13
 * Enter a message: This is a secret message.
 * Encoded message: Guvf vf n frperg zrffntr.
 * Note that the transformation applies only to letters; any other characters are
 * copied unchanged to the output. Moreover, the case of letters is unaffected:
 * lowercase letters come out as lowercase, and uppercase letters come out as
 * uppercase. You should also write your program so that a negative value of
 * shift means that letters are shifted toward the beginning of the alphabet
 * instead of toward the end, as illustrated by the following sample run:
 * CaesarCipher
 * This program encodes a message using a Caesar cipher.
 * Enter the number of character positions to shift: -1
 * Enter a message: IBM 9000
 * Encoded message: HAL 9000
 *
 */

#include <iostream>
#include <string>
using namespace std;

string encode_caesar_cipher(string str, int shift);

int main()
{
  cout << "This program encodes the messages using caesar cipher." << endl;
  cout << "Enter the string to encode: ";
  string str;
  getline(cin, str);
  cout << "Enter the shift in character: ";
  int shift;
  cin >> shift;
  cout << "The encoded string: "
       << encode_caesar_cipher(str, shift) << endl;
  return 0;
}

/*
 * Function: encode_caesar_cipher
 * Usage: string p = encode_caesar_cipher(str, shift)
 * ----------------------------------
 * Returns the new string encoded in caesar cipher with
 * characters shifted by 'shift' amount.
 */
string encode_caesar_cipher(string str, int shift)
{
  string s;

  if (shift < 0)
    shift = 26 + shift;
  
  for (auto c: str)
  { 
    if (isalpha(c))
    {
      if (isupper(c))
      {
        c = 'A' + ((c - 'A' + shift) % 26);
        s.push_back(c);
      }
      else
      {
        c = 'a' + ((c - 'a' + shift) % 26);
        s.push_back(c);
      }
    }
    else
    {
      s.push_back(c);
    }
  }
  
  return s;
}  
  

    
