//Operator Overloading!
//>> and << operator overloading
#include <iostream>
#include<string>
using namespace std;


class Student
{
	
friend	ostream &operator<<(ostream &, const Student &); //cout<< operator overloaded
friend	istream &operator>>(istream &, Student &);//cin>> operator overloaded

	
	
private:
	string fname,lname;	
	
};



ostream &operator<<(ostream &output , const Student &a )
	{
		output<<a.fname;
		output<<a.lname;
		
		
		return output;
	}
	

istream &operator>>(istream &input ,Student &a )
	{
		input>>a.fname;
		input>>a.lname;
		
	}	
	
int main()
{
	Student S;
	
	cin>>S;
	cout<<S;
	
	
	
	return 0;
}
