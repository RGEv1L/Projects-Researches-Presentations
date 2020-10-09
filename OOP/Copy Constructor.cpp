#include<iostream>
using namespace std;

class Student
{	
	public:
	Student(int a = 1)
	{
		x = a;
	
		
	}
	
	Student(const Student &X)
	{
		x = X.x; // Only X is being copied!
	
		
	}
	public:
			int x,y;
	

};


int main()
{
	
	Student A(2);
	//Student B;
	A.y = 6; 
	Student B=A; // Copy constructor
	cout<<A.x<<B.x<<B.y; //B.y not specied in copy constructor . So it is not being copied!
	
	
	
	
	
	return 0;
}
