/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 11
*/

#include <iostream>
#include <string>  
using namespace std;

const int MAX = 6;
string makeKey(), choice();
void makePoly(string, char[][MAX]);
string getChoice();
string makeInput();
string tokenize (string);
string encrypt (string, char[][MAX]);
string decrypt (string, char[][MAX]);
void findRowCol (char, char[][MAX], int&, int&);

int main()
{
 string key = makeKey();
 char poly[MAX][MAX];
 string output;
 makePoly(key, poly); 
 string choice = getChoice();
 string input = makeInput();
 if (choice == "encrypt")
 {
  input = tokenize(input);
  output = encrypt (input, poly);
 }
 if (choice == "decrypt")
 {
  output = decrypt (input, poly);
 }
 cout << output << endl;
 return 0;
}

string makeKey()
{ 
 string key;
 cout << "Enter up to 25 UC chars, no duplicates, no J " << endl;
 getline(cin,key);

 for (int i = 0; i < 26; i++)
  {
   char ch = 'A' + i;
   if (ch != 'J') 
     if (key.find(ch) == string::npos)
       key = key + ch;
  }
  key += "0123456789!";
 return key;
}


void makePoly(string key, char poly[][MAX])
{
 int k = 0;
 for (int row = 0; row < MAX; row++)
   for (int col = 0; col < MAX; col++)
    {
     poly[row][col] = key.at(k); 
     k++;
    }
}

string getChoice()
{
 string choice;
 cout << "'encrypt' or 'decrypt'" << endl;
 getline (cin, choice);
 return choice;
}

string makeInput ()
{
 string input;
 cout << "Enter input less than 80 characters" << endl;
 getline (cin, input);
 return input;
}

string tokenize (string input)
{
 for (int i = 0; i < input.length(); i++)
 {
  if (!isalpha (input.at(i)) && !(input.at(i) <= '9' && input.at(i) >= '0'))
  {
   input.erase(input.begin () + i);
   i--;
  }
  if (islower (input.at(i)))
   input.at(i) = toupper (input.at(i));
 }
 return input;
}

string encrypt (string input, char poly[][MAX])
{
 string output;
 int numbers [2 * input.length()], row, col, x = 0;

 for (int i = 0; i < input.length(); i++)
 {
  findRowCol (input.at(i), poly, row, col);
  numbers[i] = row;
  numbers[i + input.length()] = col;
 }
 for (int i = 0; i < input.length(); i++)
 {
  row = numbers [x];
  col = numbers [x+1];
  output += poly [row][col];
  x += 2;
 }
 return output;
} 

string decrypt (string output, char poly[][MAX])
{
 string decode;
 int numbers [2 * output.length()], row, col, x = 0;
 for (int i = 0; i < output.length(); i++)
 {
  findRowCol (output.at(i), poly, row, col);
  numbers[x] = row;
  numbers[x + 1] = col;
  x += 2;
 }
 for (int i = 0; i < output.length(); i++)
 {
  row = numbers [i];
  col = numbers [i + output.length()];
  decode += poly [row][col];
 }
 return decode;
}

void findRowCol (char ch, char poly[][MAX], int& row, int& col)
{
 for (int j = 0; j < MAX; j++)
  for (int k = 0; k < MAX; k++)
    if (ch ==poly[j][k])
    {
     row = j;
     col = k; 
    }
}
