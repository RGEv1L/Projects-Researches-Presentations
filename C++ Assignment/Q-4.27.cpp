/*  Q-4.27

Input an integer containing only
0s and 1s (i.e., a “binary” integer) and print its decimal equivalent. Use the modulus and division
operators to pick off the “binary” number’s digits one at a time from right to left. Much as in the
decimal number system, where the rightmost digit has a positional value of 1, the next digit left has
a positional value of 10, then 100, then 1000, and so on, in the binary number system the rightmost
digit has a positional value of 1, the next digit left has a positional value of 2, then 4, then 8, and so
on
*/

#include <iostream>
using namespace std;

int main()
{
	int binary;      			// binary number
	int decimal = 0;   	// combining decimal number
	int Rank = 1; 	// rank
	int digit;					// processing digit 
	cout << "Enter binary number (only 0's and 1's, maximum 10 digits long): ";
	cin >> binary;
	while (binary > 0)       
	{
		digit = binary % 10;
		decimal  = decimal + digit * Rank;
		binary = binary / 10;
		Rank = Rank * 2;
	}
	cout << "Decimal equivalent of entered binary number is: " << decimal << endl;

return 0;
}
