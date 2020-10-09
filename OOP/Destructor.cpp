#include<iostream>
using namespace std;

class Student
{	
	public:
		Student(int a = 1)
			{
			x = a;
	
		
			}	
	
		int x,y;
	
	~Student()
	{	
		cout<<"The Distructor is called";
	
	}

};

void temp()
	{
		cout<<"Hello";
		Student S;
		cout<<"bye";
		
	}




int main()
{
		
	temp();
	cout<<"Hi";
	
	
	
	
	return 0;
}
