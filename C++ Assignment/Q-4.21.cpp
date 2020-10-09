/*  Q-4.21
Whatdoes this program print?
*/

#include <iostream>
using namespace std;

int main()
{
	int count = 1; // initialize count

	while (count <= 10 ) // loop10times
	{
		// outputline of text
		cout << (count % 2 ? "****" : "++++++++" )<<endl;
		++count; // increment count
	} // end while
return 0;
} 



// Answer:
/* 
	****
	++++++++
	****
	++++++++
	****
	++++++++
	****
	++++++++
	**** 
	++++++++
*/
