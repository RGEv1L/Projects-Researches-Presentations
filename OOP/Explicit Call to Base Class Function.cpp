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
	void show()
	{	
		Base::show(); //Explicit Call to Base Class Function
		cout<<"Derived class function called";
			
	}	
	
	
	
	
};

int main()
{
	
	Base A;
	Derived B;

	B.show();	

	
	
	
	return 0;
}
