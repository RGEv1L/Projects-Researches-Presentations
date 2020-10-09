//Operator Overloading +
#include<iostream>
using namespace std;

class Student
{
	
public:
	Student(int x)
	{
		marks=x;
		
	}
	
	Student operator+(Student &s)
	{
		
		this->marks = this->marks + s.marks;
		
		return this->marks;
	}
	
	void getmarks()
	{
		cout<<marks;
	}
	
	
	
private:
	int marks;
	
};



int main()
{	
	Student S1,S2(5),S3(7),S4(4);
	
	S1= S2 + S3 + S4;
	
	S1.getmarks();
	
	return 0;
}
