/*  Q-4.17

The process of finding the largest number (i.e., the maximum of a group
of numbers) is used frequently in computer applications. For example, a program that determines
the winner of a sales contest inputs the number of units sold by each salesperson. The salesperson
who sells the most units wins the contest. Write a C++ program that uses a while statement to determine
and print the largest number of 10 numbers input by the user.
*/

#include<iostream>
using namespace std;


int main()
{
int counter = 1,number,largest = 0;

	cout<<"Welcome to Find the Largest Number Calculator\n";
		
while	(counter <= 10) 
{
	cout<<"Enter Number of units saled:";
	cin>>number;
	
if (number > largest) 	//Largest number finder
	largest = number;	
	
counter++ ;
}

	cout<<"\nLargest Number of Units saled is:"<<largest<<endl;	
	return 0;
}
