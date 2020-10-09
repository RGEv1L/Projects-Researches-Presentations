//Polymorhism without virtual function
#include<iostream>
#include<string>
using namespace std;

class Person
{
	public:
	
		Person(string x , int y)	
		{
			name = x;
			ID = y;
		}
		
		void print()
		{
			cout<<"Name:"<<name<<"\nID"<<ID;
			
		}
	
	private:
		string name;
		int ID;
};


class Student : public Person
{
	public:
		Student ( string x , int y , string z , int m) : Person(x,y)
		{
			course = z;
			marks = m;
		
		}
	
		void print()
		{
			cout<<"Course:"<<course<<"\nMarks:"<<marks;
			
			
		}
		

	
	private:
		string course;
		int marks;
	
	
};

int main()
{	
	Person *p;
	Student S("Ammar",170100,"English",98);
	
	//invoking Base Class print function and printing base class data of derived class.
	
	//Base class pointer pointed at derived class object can only invoke base class print function.However if we had declared
	//print function virtual,we would be able to call derived class print function via base class pointer!
	p=&S;
	p->print();
	
	return 0;
}
