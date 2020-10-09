/*  Q-4.5

Combine the statements that you wrote in Exercise 4.4 into a program that calculates and
prints the sum of the integers from 1 to 10. Use the while statement to loop through the calculation
and increment statements. The loop should terminate when the value of x becomes 11.
*/

#include<iostream>
using namespace std;


int main()
{
int sum,x;
	
	x = 1;
	sum = 0;
	
while (x <= 10)	
{
	sum = sum + x;	
	cout<<"Sum is:"<<sum<<endl;
	x++;
}
    cout<<x;  //Loop Terminated @ 11th integer
    
	return 0;
}

