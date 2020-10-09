/*  Q-4.19

Using an approach similar to that in Exercise 4.17, find
the two largest values among the 10 numbers. [Note: You must input each number only once.]
*/

#include<iostream>
using namespace std;

int main()
{
	int counter = 1,number,largest_1 = 0,largest_2 = 0;

	cout<<"Welcome to Find the Largest Number Calculator\n";
		
while	(counter <= 10) 
{
	cout<<"Enter Number of units saled:";
	cin>>number;
	
if (number > largest_1) 	//1st Largest number finder
	largest_1 = number;
		
if (number > largest_2 && number < largest_1)  //2nd Largest number finder
	largest_2 = number;
	
counter++ ;
}
	
	
	cout<<"\nFirst Largest Number is:"<<largest_1<<"\nSecond Largest Number is:"<<largest_2<<endl;
	
	return 0;
}
