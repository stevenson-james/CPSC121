/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 2
*/

#include <iostream>
using namespace std;

int main()
{
double distance, mpg, price, total;

//Get distance from Spokane to Las Vegas
cout << "What is the distance from Spokane to Las Vegas? (in miles) ";
cin >> distance;

//Get miles per gallon
cout << "How many miles does your car get per gallon? ";
cin >> mpg;

//Get price of gas
cout << "How much does gas cost? ";
cin >> price;

//calculate total price
total=distance/mpg*price;

//display the total price of the trip
cout << "It will cost $" << total << " to drive from Spokane to Las Vegas" << endl;

 return 0;
}
