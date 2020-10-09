/*  Q-4.4

Write C++ statements to accomplish each of the following tasks.
a) Declare variables sum and x to be of type int.
b) Set variable x to 1.
c) Set variable sum to 0.
d) Add variable x to variable sum and assign the result to variable sum.
e) Print "The sum is: " followed by the value of variable sum.
*/

#include<iostream>
using namespace std;

int main()
{
int sum,x;
	
	x = 1;
	sum = 0;
	sum = sum + x;
	
	cout<<"Sum is:"<<sum;      //Total result of addition

	return 0;
}

