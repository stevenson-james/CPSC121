/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 6
*/

#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 170;
bool prime (int);
bool even (int);
int main()
{
	int i = 0, x, y, array [MAX];
	char inp;
	cout << "Enter min (> 1): ";
	cin >> x;
	cout << "Enter max (<= 1000): ";
	cin >> y;
	while (x <= y)
	{
		if (prime(x))
		{
			array [i] = x;
			i++;
		}
		x++;
	}
	array[i] = '\0';
	i = 0;
	while (array[i] != '\0')
	{
		cout << array[i] << endl;
		i++;
	}
	cout << "Would you like to see a proof for Godlbach's conjecture? (y/n) (min must be 2 and max must be 1000)" << endl;
	cin >> inp;
	if (inp == 'y')
	{
		if (array [0] == 2)
			cout << "4	2	2" << endl;
		for (int num = 6; num <= 1000; num++)
		{
			if (even (num))
				for (int i = 0; array [i] != '\0'; i++)
				{
					if (3 + array [i] == num)
					{	
						cout << num << "	3	" << array [i] << endl;
						num++;
					}
					else
						if (5 + array [i] == num)	
						{	
							cout << num << "	5	" << array [i] << endl;
							num++;
						}
						else
							if (7 + array [i] == num)		
							{
								cout << num << "	7	" << array [i] << endl;
								num++;
							}
					
				}
		}
	}

	return 0;
}

/*
Pre: x is an integer > 1
Post: return true if x is prime, false if x is not prime
*/

bool prime (int x)
{
	int i = 2;
	if (x>1 && x<=1000)
	{
		while (i <= sqrt (x) && x % i != 0)
			i++;
		if (x % i != 0 || x == 2)
			return true;
		else
			return false;
	}
	else
		return false;
}

/*
Pre: num is a positive integer
Post: retrun true if num is even, false otherwise
*/

bool even (int num)
{
	if (num % 2 == 0)
		return true;
	else
		return false;
}
