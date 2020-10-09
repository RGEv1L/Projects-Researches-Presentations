/*  Q-4.25
 
Write a program that reads in the size of the side of a square then prints
a hollow square of that size out of asterisks and blanks. Your program should work for squares of all
side sizes between 1 and 20.
*/

#include<iostream>
using namespace std;

int main()
{
int size,i=1,j=1,k=1;
		cin>>size;


if(size > 1 && size < 20)  //Dimentions Check
{

while(i <= size)        //Line Jump
{
	if(i == 1 || i == size) //First and Last line Printing
	{
	
		while(j<=size)
		{
		cout<<"*";
		j++;
		}
	}
	
	else				//Printing of inner lines
	{
		cout<<"*";
		while (j < size-1)
			{
			cout<<" ";
			j++;					
			}		
		cout<<"*";
	}
	j=1;
	cout<<endl;
	i++;
}
}

else
cout<<"Wrong Dimentions";	
	
return 0;
}
