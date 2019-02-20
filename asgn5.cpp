/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 5
*/

#include <iostream>
using namespace std;

/*
Pre: ch is an ASCII-encoded character
Post: returns true if ch is alphabetic, false otherwise
*/

bool isAlpha (char ch)
{
  if ((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
    return true;
  return false;
}

/*
Pre: ch is an alphabetic character
Post: returns true if ch is in the first half of the alphabet, false otherwise
*/

bool firstHalf (char ch) 
{
  if ((ch >= 65 && ch < 78) || (ch >= 97 && ch <= 109))
    return true;
  return false; 
}

/*
Pre: ch is an alphabetic character
Post: returns the rotation 13 encryption of ch
*/

char encrypt (char ch)
{
  if (firstHalf(ch))
    ch += 13;
  else
    ch -= 13;
  return ch;
}

/*
Pre: inp is an ASCII encoded character
Post: Returns true if inp is 'y ' or 'n', false otherwise
*/

bool validInput (char inp)
{
  if (inp == 'y' || inp == 'n')
    return true;
  else
    return false;
}

const int MAX = 81;
int main ()
{
  int i;
  char inp = 'y', ch [ MAX];
  while (inp == 'y')
  {
    i = 0;
    cout << "Enter a string of no more than " << MAX << " characters" << endl;
    cin.getline(ch, MAX - 1, '\n');
    cout << "Original phrase: " << ch << endl;
    while (i < MAX && ch[i] != '\0')
    {
      if (isAlpha (ch [i]))
        {
	  ch [i] = encrypt (ch [i]);
	  i++;
	}
      else
	i++;
    }
    cout << "Encoded phrase: " << ch << endl;
    cout << "Would you like to run the program again? (y/n)" <<endl;
    cin >> inp;
    while (validInput (inp)== false)
    {
	cout << "Invalid response. Enter y or n" << endl;
	cin >> inp;
    }
    cin.ignore();
  }
  return 0;
}



