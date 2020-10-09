/*  Q-4.29

Write a program that prints the powers of the integer
2, namely 2, 4, 8, 16, 32, 64, etc. Your while loop should not terminate (i.e., you should create an
infinite loop). To do this, simply use the keyword true as the expression for the while statement
*/
#include <iostream>
using namespace std;

int main()
{
	int number = 2;
	while (true)    //infinite loop
	{
		cout << number << endl;
		number = number * 2;
	}

return 0;
}

/*
The integer answer soon begins to be Zero as the
number become larger than int can hold.
