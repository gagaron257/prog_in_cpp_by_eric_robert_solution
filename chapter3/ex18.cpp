/*
 * File: ex18.cpp
 * ------------------------
 * Although they are certainly simple, Caesar ciphers are also extremely easy to
 * break. There are, after all, only 25 values for the number of characters to shift.
 * If you want to break a Caesar cipher, all you have to do is try each of the 25
 * possibilities and see which one translates the original message into something
 * readable. A better scheme is to allow each letter in the original message to be
 * represented by an arbitrary letter instead of one a fixed distance from the
 * original. In this case, the key for the encoding operation is a translation table
 * that shows what each of the 26 letters becomes in the encrypted form. Such a
 * coding scheme is called a letter-substitution cipher.
 * The key in a letter-substitution cipher is a 26-character string that indicates
 * the translation for each character in the alphabet in order. For example, the
 * key "QWERTYUIOPASDFGHJKLZXCVBNM" indicates that the encoding process
 * should use the following translation rule:
 * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
 * Q W E R T Y U I O P A S D F G H J K L Z X C V B N M
 * Write a program that implements encryption using a letter-substitution
 * cipher. Your program should be able to duplicate the following sample run:
 * Letter substitution cipher.
 * Enter a 26-letter key: QWERTYUIOPASDFGHJKLZXCVBNM
 * Enter a message: WORKERS OF THE WORLD UNITE!
 * Encoded message: VGKATKL GY ZIT VGKSR XFOZT!
 */

#include <iostream>
#include <string>
using namespace std;

string encode_letter_subs_ciper(string str, string key);

int main()
{
  cout << "This program encodes the messages using Letter subsitution cipher." << endl;
  cout << "Enter the string to encode: ";
  string str;
  getline(cin, str);
  cout << "Enter the key string: ";
  string key;
  cin >> key;
  cout << "The encoded string: "
       << encode_letter_subs_ciper(str, key) << endl;
  return 0;
}

/*
 * Function: encode_letter_subs_ciper
 * Usage: string p = encode_letter_subs_ciper(str, key)
 * ----------------------------------
 * Returns the new string encoded in letter subsitution 
 * cipher format with the help of 'key' provided.
 */
string encode_letter_subs_ciper(string str, string key)
{
  string s;
  int key_index{0};

  for (auto c: str)
  {
    if (isalpha(c))
    {
      key_index = toupper(c) - 'A';
      s.push_back(key[key_index]);
    }
    else
    { 
      s.push_back(c);
    }
  }
  return s;
}  
  

    
