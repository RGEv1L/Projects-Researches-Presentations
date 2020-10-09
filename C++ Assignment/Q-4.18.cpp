/*  Q-4.18

(Tabular Output) Write a C++ program that uses a while statement and the tab escape sequence
\t to print the following table of values:
*/

#include<iostream>
using namespace std;

int main()
{
int N = 1;
	
	cout<<"Welcome to Tabular Viewer\n";
	cout<<"N\t10*N\t100*N\t100*N\n";	
	
while (N <= 5 )
{
	cout<<N<<"\t"<<N*10<<"\t"<<N*100<<"\t"<<N*1000<<endl;

N++ ;
}	
	
	
	
	
}
