/*  Q-4.28

Write a program that displays the checkerboard pattern
shown below. Your program must use only three output statements, one of each of the following
forms:
cout << "* ";
cout << ' ';
cout << endl;
*/

#include<iostream>
using namespace std;

int main()
{
int x = 1,y = 1;	
	
while(x <= 8)        //new line loop
{
	if(x % 2 == 0)    // alternating pattern generator
	cout<<" ";
	
		while (y <= 8)
		{
		cout<<"*";    //asteric printing loop
		y++;
	     }
	cout<<endl;
	x++;
    y=1;
}
	return 0;
}
