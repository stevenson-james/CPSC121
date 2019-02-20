/*
CPSC 121-03
James Stevenson
jstevenson4
Final
*/

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int GMAX = 10;

void load (int[]);
void display (int[]);
void bubble (int array[]);
int getMax (int min);

int main()
{
 int array[GMAX];
 unsigned seed = time (0);
 srand (seed);
 load (array);
 display (array);
 bubble (array);
 display (array);

 return 0;
}

void load (int array[])
{
 int min, max, value;
 cout << "Enter min" << endl;
 cin >> min;
 max = getMax(min);
 for(int i = 0; i < GMAX; i++)
 {  
   value = (rand() % (max - min + 1)) + min;
   array[i] = value;
 }
}

void display (int array[])
{
 for(int i = 0; i < GMAX; i++)
  cout << array[i] << endl;
}

void bubble (int array[])
{
 for (int i = GMAX-1; i > 0; i--)
		for (int j = 0; j < i; j++)
			if (array[j] > array[j+1])
			{
				int buf = array[j];
				array[j] = array[j+1];
				array[j+1] = buf;
			}
}

int getMax (int min)
{
 int max;
 double firstmax;
 cout << "Enter max" << endl;
 cin >> firstmax;
 while (firstmax <= min || firstmax != static_cast <int> (firstmax))
 {
  cout << "Max must be greater than min and an integer value" << endl << "Enter max" << endl;
  cin >> firstmax;
 }
 max = static_cast <int> (firstmax);
 return max;
}
