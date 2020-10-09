/*  Q-4.26

A palindrome is a number or a text phrase that reads the same backward as forward.
For example, each of the following five-digit integers is a palindrome: 12321, 55555, 45554 and
11611. Write a program that reads in a five-digit integer and determines whether it’s a palindrome
*/


#include<iostream>
using namespace std;

int main()
{
int Fwd,Rw = 0;

	cout<<"Enter Number 5 of Digits to check Whether it is Palindrome or not\n";
	cin>>Fwd;
   
	Rw = Fwd/10000;					//Number Reversing Calculations
	Rw = Rw  + ((Fwd/1000)%10)*10 ;
	Rw = Rw  + ((Fwd/100)%10)*100 ;	
	Rw = Rw  + ((Fwd/10)%10)*1000 ;	
	Rw = Rw  + (Fwd%10)*10000 ;
    
		cout<<"Number Reversed:"<<Rw<<endl;
	
	if (Fwd == Rw)             		//Palindrome Check
	cout<<"Palindrome indeed!";
	else
	cout<<"Not a Palindrome";
	
	return 0;
}
