#include<iostream>
using namespace std;

class Base
{	
public:
	Base()
	{
		a = 10 ;
	}	
	

	int a;	// To be inherited by the derived class

};


class Derived : public Base
{
public:
	Derived()
	{
		w = 20;
		
	}	
	int x;	
	
	int getw()
	{
		return w;
		
	}

	int w;		//Data of derived Class not accessible via pointer of base class
	
	
};

int main()
{
	Base *p;
	Base B;
	Derived D;
	
	//Setting Values
	p=&D;
	p->a= 20;
	p=&B;
	p->a = 10;
	
	//Getting Values
	p=&D;
	cout<<p->a;
	p=&B;
	cout<<p->a;
	return 0;
}
