/*  Q-4.23

State the output for each of the following when x is 9 and y is 11
and when x is 11 and y is 9. The compiler ignores the indentation in a C++ program. The C++ compiler
always associates an else with the previous if unless told to do otherwise by the placement of
braces {}. On first glance, you may not be sure which if and else match, so this is referred to as
the “dangling-else” problem. We eliminated the indentation from the following code to make the
problem more challenging
*/
#include<iostream>
using namespace std;

int main()
{
int x ,y,c=1;


while ( c <= 2)
{

if (c == 1)
{
	x  =  9;
	y  =  11; 
}

if (c == 2)
{
	x  =  11;
	y  =  9;
	
}

// a)
if (x< 10 )
	if (y> 10 )
		cout<< "*****" << endl;
	else
		cout<< "#####" << endl;
cout<< "$$$$$" << endl;

	
// b)
if (x< 10 )
{
	if (y> 10 )
		cout<< "*****" << endl;
}
else
{
	cout<< "#####" << endl;
	cout<< "$$$$$" << endl;
}

c++;
}
return 0;
}

/* Answer:

1a. x = 9, y = 11
	*****

1b. x = 9, y = 11
	*****
	$$$$$
	
2a. x = 11, y = 9
	#####
	$$$$$	
	
2b. x = 11, y = 9
	$$$$$
*/
