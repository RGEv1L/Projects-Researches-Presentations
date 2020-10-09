/*  Q-4.34

(Factorial) The factorial of a nonnegative integer n is written n! (pronounced “n factorial”)
and is defined as follows:
n! = n · (n – 1) · (n – 2) · … · 1 (for values of n greater than 1)
and
n! = 1 (for n = 0 or n = 1).
For example, 5! = 5 · 4 · 3 · 2 · 1, which is 120. Use while statements in each of the following:
a) Write a program that reads a nonnegative integer and computes and prints its factorial.
b) Write a program that estimates the value of the mathematical constant e by using the
formula:
Prompt the user for the desired accuracy of e (i.e., the number of terms in the summation).
c) Write a program that computes the value of ex by using the formula
Prompt the user for the desired accuracy of e (i.e., the number of terms in the summation).
*/



#include<iostream>
#include<cmath>
using namespace std;

int main()
{
int num,acc,n = 1;
float answer = 1;
	
	cout<<"Enter Number to calculate Factorial:";
		cin>>num;

while( n <= num  )                // Factorial Calculator loop
{
	answer = answer * n ;  		  //Factorial formula
	n++ ;
}		
	
	cout<<"\nFactorial:"<<answer<<endl;
	
system ("pause");
system ("cls");

//b)

num    = 0;
answer = 1;
n 	   = 1;
float answer2= 1;
	cout<<"Enter Accuracy:";
	cin>>acc;
	



while( n <= acc  )
{
	num = n;
	answer = 1;
	
	while( num > 0  )              // Factorial counter for every n
{
	answer = answer * num;
	num-- ;
}	
	answer2 = answer2 + (1/answer);      // exp function formula

n++	;	
}		
	cout<<"\nAccuracy is:"<<answer2<<endl;

system ("pause");
system ("cls");


//c)
num    = 0;
answer = 1;
n 	   = 1;
answer2= 1;

	cout<<"Enter Accuracy:";
	cin>>acc;

while( n <= acc  )
{
	num = n;
	answer = 1;
	
	while( num > 0  )              // Factorial counter for every n
{
	answer = answer * num;
	num-- ;
}	
	answer2 = answer2 + (pow(acc, n) / answer);	 // exp power function formula
n++	;	
}		
	cout<<"\nAccuracy is:"<<answer2;

	
	
return 0;
}
