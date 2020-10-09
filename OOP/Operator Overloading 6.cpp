//Binary Operator Overloading!
#include<iostream>
using namespace std;

class Student
{
	public:
		
		Student(int x)
		{
			marks = x;
		}
	
		Student operator+=(Student &obj) //Object type addition
		{
			
			this->marks = this->marks + obj.marks;
			
		}
	
		Student operator+=(double x)	//Overloaded form for integers type
		{
			
			this->marks = this->marks + x;
			
		}
	
		void print()
		{
			cout<<marks;
		}
	
	private:
		int marks;
	
};

int main()
{
	Student S1(5),S2(10);
	
	S1+=S2;
	S1.print();
	
	S1+=5;
	S1.print();
	
	
	
	return 0;
}
