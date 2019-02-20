/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 8
*/
#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;
void getMultInv (int[]);
int alphToInt (char);
int intToAlph (char, int);
int multToInv (int, int);
char encrypt_decrypt (char, int, int);
void display (char[]);
bool goodMult (int);
bool isYes (char);
bool badInp (char);
bool goodShift (int);
const int MAX = 81;
int main()
{
	int mult, shift;
	int inv[]={0,1,0,9,0,21,0,15,0,3,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25};
	char line [MAX], inp = 'y';
	while (isYes(inp))
	{
		cout << "Enter multiplier" << endl;
		cin >> mult;
		if (goodMult(mult))
		{
			cout << "Enter shifter" << endl;
			cin >> shift;
			if (goodShift(shift))
			{
				cin.ignore();
				cout << "Enter plaintext" << endl;
				cin.getline (line, MAX-1, '\n');
				for (int i = 0; i < strlen(line); i++)
						line[i] = encrypt_decrypt(line[i], mult, shift);
				display(line);
				cout << endl;
				mult = multToInv(inv[mult], mult);
				for (int i = 0; i < strlen(line); i++)
						line[i] = encrypt_decrypt(line[i], mult, shift);
				display(line);
				cout << endl;
			}
			else
				cout << "Illegal shifter" << endl;
		}
		else
			cout << "Illegal multiplier" << endl;
		cout << "Would you like to run the program again? (y/n)" << endl;
		cin >> inp;
		while (badInp(inp))
		{
			cout << "Please enter y or n" << endl;
			cin >> inp;
		}
		cin.ignore();
	}
	return 0;
}

/*
Pre: inv is an integer array stored with multiplicative inverses % 26 as described in class, num is an integer % 26 with a multiplicative inverse
Post: returns the multiplicative inverse of num using the technique described in class
*/

int multToInv (int inv, int num)
{
		return -1*inv;

}

/*
Pre: ch is an ascii-encoded character, shift is a shift amount
Post: if ch is alphabetic, returns the encrypted/decrypted ch using the affine cypher, else returns ch
*/

char encrypt_decrypt (char ch, int mult, int shift)
{
	int pos=alphToInt(ch);
	if (isalpha(ch))
	{
		if (mult < 0)
		{
			shift = mult * shift;
			while (shift < 0)
				shift = shift + 26;
			mult = mult* -1;
		}
		pos = (mult*pos + shift) % 26;
	ch = intToAlph (ch, pos);
	}
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

/*
Pre: line contains either the plaintext or the ciphertext, encoded as a C-string
Post: displays the contents on one line, followed by an end of line character
*/

void display (char line[])
{
	for (int i = 0; i < strlen(line); i++)
		cout<<line[i];
}

/*
Pre: shift is an integer
Post: returns true if the inv[mult] exists, false otherwise
*/

bool goodMult (int mult)
{
	if (mult % 2 != 0 && mult != 13)
		return true;
	return false;
}

/*
Pre: shift is an integer
Post: returns true if 0 < shift < 26, false otherwise
*/

bool goodShift (int shift)
{
	if (shift < 26 && shift >= 0)
		return true;
	return false;
}

/*
Pre: inp is either 'y' or 'n'
Post: if inp is 'y' return true, false otherwise
*/

bool isYes (char inp)
{
	if (inp == 'y')
		return true;
	return false;
}

/*
Pre: inp is an ascii encoded character
Post: if inp is 'y' or 'n' return false, true otherwise
*/

bool badInp (char inp)
{
	if (inp == 'y' || inp == 'n')
		return false;
	return true;
}

