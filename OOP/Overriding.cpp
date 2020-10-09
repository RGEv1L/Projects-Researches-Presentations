//It is the redefinition of base class function in its derived class with same signature i.e return type and parameters.

#include<iostream>
using namespace std;

class Base
{
public:
	void show()
	{
		cout<<"Base class function called\n";
			
	}	
	
	
};

class Derived : public Base
{
public:
	void show()	//Overiding the same base class Function that is inherited in derived class
	{	
		
		cout<<"Derived class function called";
			
	}	
	
	
	
	
};

int main()
{
	
	Base A;
	Derived B;
	A.show();
	B.show();	

	
	
	
	return 0;
}
