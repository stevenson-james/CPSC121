/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 10
*/

#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;
int getAlpha();
int getBeta();
int getBeta();
char getChoice ();
int makePositive (int);
int multInv (int[], int);
char encDec (char, int, int, char);
int alphToInt (char);
int intToAlph (char, int);
int main()
{
 int inv[]={0,1,0,9,0,21,0,15,0,3,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25};
 char ch, choice;
 string fileName1, fileName2; 
 int alpha, beta, i=0;
 ifstream inputFile;
 ofstream outputFile;

 cout << "Enter input file name" << endl;
 getline (cin, fileName1);
 inputFile.open (fileName1);

 cout << "Enter output file name" << endl;
 getline (cin, fileName2);
 outputFile.open (fileName2);

 alpha = getAlpha();
 beta = getBeta();
 choice = getChoice();

 if (choice == 'd')
  alpha = multInv(inv, alpha);

 while (inputFile >> ch)
 {
  if (isalpha(ch) || (ch >= '0' && ch <= '9'))
  {
   outputFile << encDec (ch, alpha, beta, choice);
   i++;
   if (i % 50 == 0)
    outputFile << endl;
  }
 }

 inputFile.close();
 outputFile.close();
 return 0;
}

int getAlpha()
{
 int alpha;
 cout << "Enter alpha" << endl;
 cin >> alpha;
 while (alpha == 13 || alpha % 2 == 0 || alpha < 1 || alpha > 25)
 {
  cout << "Alpha must be an odd integer in the range [1,25] not equal to 13" << endl;
  cout << "Enter alpha" << endl;
  cin >> alpha;
 }
 return alpha;
}

int getBeta()
{
 int beta;
 cout << "Enter beta" << endl;
 cin >> beta;
 while (!(beta <= 25 && beta >= 0))
 {
  cout << "Beta must be [0,25]" << endl;
  cout << "Enter beta" << endl;
  cin >> beta;
 }
 return beta;
}

char getChoice ()
{
 char ch;
 cout << "Would you like to encode or decode? ('e' or 'd')" << endl;
 cin >> ch;
 while (ch != 'e' && ch != 'd')
 {
  cout << "You must enter 'e' or 'd'" << endl;
  cout << "Would you like to encode or decode? ('e' or 'd')" << endl;
  cin >> ch;
 }
 return ch;
}

int makePositive (int alpha)
{
 while (alpha < 0)
  alpha += 26;
 return alpha;
}
 
/*
Pre: inv is an integer array stored with multiplicative inverses % 26, alpha is an integer % 26 with a multiplicative inverse
Post: returns the multiplicative inverse of alpha
*/

int multInv (int inv[], int alpha)
{
 return inv[alpha];
}

/*
Pre: ch is an ascii-encoded character, beta is a shift amount
Post: if ch is alphabetic, returns the encrypted/decrypted ch using the affine cypher, else returns ch
*/

char encDec (char ch, int alpha, int beta, char choice)
{
 int pos=alphToInt(ch);
 if (isalpha(ch))
 {
  if (choice == 'd')
  {
   beta *= alpha * -1;
   while (beta < 0)
   beta = makePositive (beta);
  }
  pos = (alpha*pos + beta) % 26;
  ch = intToAlph (ch, pos);
 }
 if (islower(ch))
    ch -= 32;
 return ch;
}

/*
Pre: ch is an alphabetic charater, upper is true if ch is uppercase, false otherwise
Post: The positional value of ch in the alphabet is returned
*/

int alphToInt (char ch)
{
 int pos;
 if (isupper(ch))
  pos = ch - 65;
 else
  pos = ch - 97;
 return pos;
}

/*
Pre: pos is an integer in the range 0 <= pos <= 25, upper is true if the character associated with pos is upper case, false otherwise
Post: The alphabetic character assiciated with the positional value pos is returned
*/

int intToAlph (char ch, int pos)
{
 if (isupper(ch))
  ch = pos + 65;
 else
  ch = pos + 97;
 return ch;
}

