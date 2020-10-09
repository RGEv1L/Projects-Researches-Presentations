/*  Q-4.35

The explosive growth of Internet communications
and data storage on Internet-connected computers has greatly increased privacy concerns. The field
of cryptography is concerned with coding data to make it difficult (and hopefully—with the most
advanced schemes—impossible) for unauthorized users to read. In this exercise you’ll investigate a
simple scheme for encrypting and decrypting data. A company that wants to send data over the Internet 
has asked you to write a program that will encrypt it so that it may be transmitted more securely.
All the data is transmitted as four-digit integers. Your application should read a four-digit
integer entered by the user and encrypt it as follows: Replace each digit with the result of adding 7
to the digit and getting the remainder after dividing the new value by 10. Then swap the first digit
with the third, and swap the second digit with the fourth. Then print the encrypted integer. Write
a separate application that inputs an encrypted four-digit integer and decrypts it (by reversing the
encryption scheme) to form the original number.
*/

#include<iostream>
using namespace std;

int main()
{   
	int n;
	cin>>n;

	//Encryption Cycle
	int a = n / 1000;			// obtain digits of number
	int b = (n % 1000) / 100;
	int c = (n % 100) / 10;
	int d = n % 10;

	a = (a + 7) % 10;			//Replace each digit with the result of adding 7 to the digit and getting 
	b = (b + 7) % 10;			//the remainder after dividing the new value by 10. 
	c = (c + 7) % 10;
	d = (d + 7) % 10;
	n= c * 1000 + d * 100 + a * 10 + b; // swap a-c and b-d; generate result number 
	
			cout<<"Encrypted Number:"<<n<<endl;  //Numbers encrypted!
	
	a,b,c,d=0;    //Parameters Resetting
	
	
	//Decryption Cycle
	a = n / 1000;				// obtain digits of number
	b = (n % 1000) / 100;
	c = (n % 100) / 10;
    d = n % 10;
	
	
	a = (a + 3) % 10;			// the remainder after dividing the new value by 10. 
	b = (b + 3) % 10;			// Replace each digit with the result of substract 7 to the digit and getting
	c = (c + 3) % 10;
	d = (d + 3) % 10;
	cout<<"Decrypted Number:"<<c * 1000 + d * 100 + a * 10 + b;

	
	return 0;
}
