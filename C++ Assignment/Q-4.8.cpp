/*  Q-4.8

Write a C++ program that uses the statements in Exercise 4.7 to calculate x raised to the y
power. The program should have a while repetition statement.
*/

#include<iostream>
using namespace std;

int main()
{
int x,y,i = 1,power = 1;   //All  Declarations
	
	cin>>x>>y;
	
while (i <= y)      //Repitition loop 
	{
		power = power * x;
		i++;
	};
	cout << "x power y is: " << power << endl;	
	
	
	return 0;
}
