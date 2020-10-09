/*  Q-4.22

What does the following program print?
*/

#include <iostream>
using namespace std;

int main()
{
	int row = 10; // initialize row
	int column; // declare column

	while (row >= 1 ) // loop until row <1
	{
		column = 1; // setcolumn to 1asiterationbegins

		while (column <= 10 ) // loop 10 times
		{
			cout << (row % 2 ? "<" : ">" ); // output
			++column; // increment column
		} // end inner while
		--row; // decrement row
		cout << endl; // begin newoutput line
	}

return 0;
}


/* Answer:
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
>>>>>>>>>>
<<<<<<<<<<
*/
