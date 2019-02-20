/*
CPSC 121-03
James Stevenson
jstevenson4@zagmail.gonzaga.edu
Assignment 3
*/

#include <iostream>
using namespace std;

int main()
{
  //set up larger loop for base 10 to binary calculation
  char repeat;
  repeat = 'Y';
  while (repeat == 'Y')
   {
     int num, rem, ans;
     cout << endl << "Enter a base 10 integer: ";
     cin >> num;
     //set variable ans (the answer of divisions by 2) equal to the original integer
     ans = num;
     cout <<endl;
     //set loop for division by two and output of remainders until the answer of division equals 0
     while (ans > 0)
      {
        rem = ans%2; 
        cout << rem << endl << endl;
        ans /= 2;
       }
     cout << "Please read the base 2 equivalent of " << num << " from bottom to top" <<endl <<endl;
     //ask for character "Y" to indicate a continuation of the loop
     cout << "Would you like to convert another integer? (Y/N): ";
     cin >> repeat;
    }
  cout <<endl << "Thank you for using James's base 10 to binary converter! Have a nice day!" <<endl;
  
  return 0;
}