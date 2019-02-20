/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 7
*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX = 81;
char encrypt (char, int);
char decrypt (char, int);
int alphToInt (char);
int intToAlph (int);
void display (char[]);
bool goodShift (int);
bool badInp (char);
bool yes (char);
int main()
{
	int pos, shift;
	char line[MAX], inp = 'y';
	while (yes(inp))
	{
		cout << "Enter shift amount" << endl;
		cin >> shift;
		cin.ignore();
		cout << "Enter plaintext" << endl;
		cin.getline (line, MAX-1, '\n');
		if (goodShift (shift))
		{
			for (int i = 0; i < strlen(line); i++)
				if (isalpha (line[i]))
						line[i] = encrypt(line[i], shift);
			cout << "Ciphertext: " << endl;
			display (line);
			for (int i = 0; i < strlen(line); i++)
				if (isalpha (line[i]))
					line[i] = decrypt(line[i], shift);
			cout << "Plaintext: " << endl;
			display (line);
		}
		else 
			cout << "Shift must be between 1 and 26" << endl;
		cout << "Would you like to run the program again? (y/n)" << endl;
		cin >> inp;
		while (badInp (inp))
		{
			cout << "Please enter y or n" << endl;
			cin >> inp;
		}
	}
	return 0;
}

/*
Pre: ch is an ascii-encoded character, shift is a shift amount
Post: if ch is alphabetic, returns ch shifted to the right by the shift amount, else returns ch unchanged
*/

char encrypt (char ch, int shift)
{
	int pos;
	pos = alphToInt (ch);
	pos = (pos + shift) % 26;
	ch = intToAlph (pos);
return ch;
}

/*
Pre:ch is an asci-encoded character, shift is a shift amount
Post:if ch is alphabetic, returns ch shifted to the left by the shift amount, else returns ch unchanged
*/

char decrypt (char ch, int shift)
{
	int pos;
	if (shift < 26 && shift >= 0)
	{
		pos = alphToInt (ch);
		pos = (pos - shift + 26) % 26;
	}
	ch = intToAlph (pos);
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

int intToAlph (int pos)
{
	char line;
	if (isupper(line))
		line = pos + 65;
	else
		line = pos + 97;
return line;
}

/*
Pre: line contains either plaintext or ciphertext, encoded as a C-string
Post: displays the contents on one line, followed by an end of line character
*/
void display (char line[])
{
	for (int i = 0; i < strlen(line); i++) 
		cout << line[i];
	cout << endl;
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
Pre: inp is an ascii encoded character
Post: if inp is 'y' or 'n' return false, true otherwise
*/

bool badInp (char inp)
{
	if (inp == 'y' || inp == 'n')
		return false;
	return true;
}

/*
Pre: inp is either 'y' or 'n'
Post: if inp is 'y' return true, false otherwise
*/

bool yes (char inp)
{
	if (inp == 'y')
		return true;
	return false;
}
