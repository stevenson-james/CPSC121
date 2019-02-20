/*
CPSC 121-03
James Stevenson
jstevenson4
Assignment 9
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct record
	{
		int num;
		char 	ch;
	};

int getInt();
bool goodNums (int, int);
int random(int, int);
void bubbleSort(int[]);
void load(int[], record data[]);
void display(record data[]);
bool isPrime (int);
int main ()
{
	record data[20];
	int num1, num2, array[20];
	num1 = getInt();
	num2 = getInt();

	while (!goodNums(num1, num2))
	{
		cout << "First input must be less than the second input" << endl <<endl;
		num1 = getInt();
		num2 = getInt();
	}

	unsigned seed;
	seed = time(0);
	srand(seed);
	for (int i = 0; i < 20; i++)
		array[i] = random (num1, num2); 

	bubbleSort(array);

	load (array, data);

	display (data);	

	return 0;
}

int getInt()
{
	float numIn;
	int num;

	while(true)
	{
	cout << "Enter an integer in the range [0,999] (min first, then max)" << endl;
	if (cin >> numIn)
	if (floor(numIn) == numIn)
 		{ 
		num = static_cast<int>(numIn);
		if (num >= 0 && num <= 999)
		break; 
		}
	cin.clear();
	cin.ignore();
	cout << "Invalid input. Input must be an integer in the "; 
	cout << "range [0,999]" << endl << endl;
	}
	cin.clear();
	cin.ignore();
	return num;
}

bool goodNums (int num1, int num2)
{
	if (num1 < num2)
		return true;
	return false;
}

int random(int min, int max)
{
	int num;
	num = (rand() % (max - min + 1)) + min;
	return num;
}
void bubbleSort(int array[])
{
	for (int i = 19; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (array[j] > array[j+1])
			{
				int buf = array[j];
				array[j] = array[j+1];
				array[j+1] = buf;
			}
}

void load(int array[], record data[])
{
	for (int i = 0; i < 20; i++)
	{
		data[i].num = array[i];
		if (isPrime(array[i]))
			data[i].ch = 'P';
		else
			data[i].ch = 'C';
	}
}

void display(record data[])
{
	for (int i = 0; i < 20; i++)
		cout << data[i].num << " " << data[i].ch << endl;
} 

bool isPrime (int num)
{
	for (int i = 2; i < num; i++)
		if (num % i == 0)
			return false;
	return true;
}
