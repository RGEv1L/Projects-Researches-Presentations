/*  Q-4.7

Write single C++ statements or portions of statements that do the following:
a) Input integer variable x with cin and >>.
b) Input integer variable y with cin and >>.
c) Set integer variable i to 1.
d) Set integer variable power to 1.
e) Multiply variable power by x and assign the result to power.
f) Preincrement variable i by 1.
g) Determine whether i is less than or equal to y.
h) Output integer variable power with cout and <<.
*/

#include<iostream>
using namespace std;

int main()
{	
int x,y,i = 1,power = 1;  //All Declarations

	cin>>x>>y;
	
	power = power * x;
	++i;

if(i <= y)
	cout<<"\ni is less than or equal to y\n";
	
	cout<<"Power:"<<power;

	
	return 0;
}
