/*  Q-4.6

State the values of each variable after the calculation is performed. Assume that, when each
statement begins executing, all variables have the integer value 5.
a) product *= x++;
b) quotient /= ++x;
*/

#include<iostream>
using namespace std;

int main()
{
int x = 5,product = 5,quotient = 5;

	product *= x++;		//Calculations
    quotient /= ++x;
	
	cout<<"Product:"<<product<<"\nQuotient:"<<quotient<<"\nX:"<<x;
	
	
	return 0;
}
