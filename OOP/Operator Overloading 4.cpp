//Operator Overloading -
#include<iostream>
using namespace std;

class Student
{
	
public:
	Student(int x)
	{
		marks=x;
		
	}
	
	Student operator-(Student &s)
	{
		Student t(0);
		
		t.marks = this->marks - s.marks;
		
		return t;
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
	Student S1(3),S2(5),S3(7);
	
	S1= S2 - S3;
	
	S1.getmarks();
	
	return 0;
}
