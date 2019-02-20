/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 12
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream* gfopenIn(string);
ofstream* gfopenOut(string);
string getKeys1 (ifstream*);
string getKeys2 (ifstream*,string);
string encrypt (string, ifstream*);
string decrypt (string, ifstream*);
bool tokenize (char);

int main (int argc, char* argv[])
{
 string key = argv[1], input = argv[2], output = argv[3], code;
 ifstream* fkey;
 ifstream* fin;
 ofstream* fout;
 char ch, choice, letter;
 int i = 0;
 string keys1, keys2;

 fkey = gfopenIn (key);
 fin = gfopenIn (input);
 fout = gfopenOut (output);

 fkey->get(choice);
 keys1 = getKeys1(fkey);
 keys2 = getKeys2(fin, keys1);

 if (choice == 'e')
  code = encrypt (keys2, fin);
 if (choice == 'd')
  code = decrypt (keys2, fin);

 *fout << code;


 fkey->close();
 fin->close();
 fout->close();
 return 0;
}

ifstream* gfopenIn(string fileIn)
{
 ifstream* fin = new ifstream;

 fin->open(fileIn);
 if (!fin->fail())
   return fin;
 cout << "Error opening input file: " << fileIn << endl;
 exit(0);
}

ofstream* gfopenOut(string fileOut)
{
 ofstream* fout = new ofstream;

 fout->open(fileOut);

 if (!fout->fail())
   return fout;
 cout << "Error opening output file: " << fileOut << endl;
 exit(0);
}

string getKeys1 (ifstream* fkey)
{
 string keystring;
 char ch;
 while (fkey->get(ch))
  keystring = keystring + ch;
 return keystring;
}

string getKeys2 (ifstream* fin, string keys1)
{
 string keys2;
 char ch;
 int i = 0;
 while (fin->get(ch))
  if (tokenize(ch))
  {
   i = i % keys1.length();
   keys2 += keys1.at(i);
   i++;
  }
 return keys2;
}

string encrypt (string keys2, ifstream* fin)
{
 string enc;
 int i = 0;
 char ch;
 fin->clear();
 fin->seekg(0);
 while(fin->get(ch))
  if (tokenize (ch))
   if (islower(ch))
   {
    ch = (keys2.at(i) - 'A' + ch - 'A') % 26 + 'a';
    enc += ch;
    i++;
   }
   else if (ch <= '9' && ch >= '0')
    enc += ch;
 return enc;
}

string decrypt (string keys2, ifstream* fin)
{
 string dec;
 int i = 0;
 char ch;
 fin->clear();
 fin->seekg(0);
 while(fin->get(ch))
  if (tokenize (ch))
   if (islower(ch))
   {
    ch = ((ch - 'a' - (keys2.at(i) - 'A') + 26) % 26) + 'A';
    dec += ch;
    i++;
   }
   else if (ch <= '9' && ch >= '0')
    dec += ch;
 return dec;
}

bool tokenize (char ch)
{
 if (isalpha(ch) || (ch <= '9' && ch >= '0'))
  return true;
 return false;
}

