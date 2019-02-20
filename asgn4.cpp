/*
CPSC 121-03
Paul DePalma
James Stevenson
Assignment 4
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   //i for # of rows, j for # of columns, k for variable of rows loop, l for variable of column loop, x for ASCII int
   int i, j, k, l, x;
   k = l = 0;
   unsigned seed;
   //set min and max for random function based on ASCII table
   const int min = 65;
   const int max = 90;
   //use time for randomly generated characters for each character
   seed = time (0);
   srand (seed);
   cout << "How many rows would you like?" << endl;
   cin >> i;
   cout << "How many columns would you like?" <<endl;
   cin >> j;
   //set a while function for rows
   while (k < i)
   {
     //set a while function for columns
     while (l < j)
       {
	 x = (rand() % (max - min + 1)) + min;
	 char y = x;
	 cout << y <<" ";
	 l++;
       }
     l = 0;
     cout << endl;
     k++;
   }
   return 0;
}
