/*
	Q-4.3 
Write C++ statements to accomplish each of the following:
a) In one statement, assign the sum of the current value of x and y to z and postincrement
the value of x.
b) Determine whether the value of the variable count is greater than 10. If it is, print
"Count is greater than 10."
c) Predecrement the variable x by 1, then subtract it from the variable total.
d) Calculate the remainder after q is divided by divisor and assign the result to q. Write
this statement two different ways.
*/

#include<iostream>
using namespace std;

int main()
{ 
// a)
int x=2,y=3,z;

	z = x++ + y;	//Post-increment of x added with y stored in z
	
	cout<<x<<y<<z<<endl;

// b)
int count;
	cin>>count;
		
if(count  >  10)	//Check Loop
		cout<<"Count is Greater than 10\n";
	
	
// c)
int total = 100;
	x = 10;
	
	total = total - --x	;	//Pre-Increment of x subtracting total variable
							//Stored in total	
	cout<<x<<endl;

// d)
int q=20,divisor=10;
	
	q = (q / divisor) % q;	//q is divided by divisor and assigned to q again
	
	cout<<q;
	
	return 0;
}
