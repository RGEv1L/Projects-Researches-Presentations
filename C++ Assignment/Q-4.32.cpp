/*  Q-4.32

Write a program that reads three nonzero double values and determines
and prints whether they could represent the sides of a triangle.
*/

#include <iostream>
using namespace std;

int main()
{
	double s1, s2, s3;             // potential sides of triangle
	cout << "Enter lengths of 3 segments: ";
	cin >> s1 >> s2 >> s3;
	if (s1 < s2 + s3 && s2 < s1 + s3 && s3 < s1 + s2) // determine whether length of each side less than sum of two others
		cout << "This segments could represent sides of the triangle!" << endl;
	else
		cout << "This segments could NOT represent sides of the triangle" << endl;
		
return 0;

}
