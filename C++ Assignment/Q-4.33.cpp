/*  Q-4.33

Write a program that reads three nonzero integers and determines
and prints whether they could be the sides of a right triangle.
*/


#include <iostream>
using namespace std;

int main()
{
	double s1, s2, s3;             // potential sides of triangle
	cout << "Enter lengths of 3 segments: ";
	cin >> s1 >> s2 >> s3;
	
	 // determine whether length of some side squared is equal sum of two others sides squared
	if(s1 * s1 == s2 * s2 + s3 * s3 || s2 * s2 == s1 * s1 + s3 * s3 || s3 * s3 == s1 * s1 + s2 * s2)								
		cout << "This segments could represent sides of the right triangle!" << endl;
		
	else
		cout << "This segments could NOT represent sides of the right triangle" << endl;
}
