/*  Q-4.24
 Modify the following code to produce the output shown.
Use proper indentation techniques. You must not make any changes other than inserting braces. The
compiler ignores indentation in a C++ program. We eliminated the indentation from the following
code to make the problem more challenging. [Note: It’s possible that no modification is necessary.]
*/

#include <iostream>
using namespace std;

int main()
{
	int x = 5;
	int y = 8;
// a)
	if (y == 8 )
		if (x == 5 )
			cout << "@@@@@" << endl;
		else
			cout << "#####" << endl;
	cout << "$$$$$" << endl;
	cout << "&&&&&" << endl;
	cout << endl;
	
// b)
	if (y == 8 )
	{
		if (x == 5 )
			cout << "@@@@@" << endl;
	}
	else
	{
		cout << "#####" << endl;
		cout << "$$$$$" << endl;
		cout << "&&&&&" << endl;
	};
	cout << endl;

// c)
	if (y == 8 )
		if (x == 5 )
			cout << "@@@@@" << endl;
		else
		{
			cout << "#####" << endl;
			cout << "$$$$$" << endl;
		}
	cout << "&&&&&" << endl;
	cout << endl;
	
// d)
	y =7;
	if (y == 8 )
	{
		if (x == 5 )
			cout << "@@@@@" << endl;
	}
	else
		cout << "#####" << endl;
	cout << "$$$$$" << endl;
	cout << "&&&&&" << endl;
	
return 0;
}
