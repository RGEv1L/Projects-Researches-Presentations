//Operator Overloading ++
#include<iostream>
using namespace std;

class Student
{
	
public:
	Student(int x)
	{
		marks=x;
		
	}
	
	Student &operator++()
	{
		marks=marks +  1;
		
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
	Student S1(3);
	
	++S1;
	S1.getmarks();
	
	return 0;
}
