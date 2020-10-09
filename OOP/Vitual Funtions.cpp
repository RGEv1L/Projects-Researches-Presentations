#include<iostream>
using namespace std;


class Base
{
public:
	virtual	 void print()
	{
		
		cout<<"Base Class\n";
		
	}

};

class D1 : public Base
{
public:
	void print()
	{
		
		cout<<"D1 Class\n";
		
	}

};	

class D2 : public Base
{
public:
	void print()
	{
		
		cout<<"D2 Class";
		
	}

};	


int main()
{
	Base B,*p;
	D1 d1;
	D2 d2;
	
	p=&B;
	p->print();
	
	p=&d1;
	p->print();
	
	p=&d2;
	p->print();
	
	
	
	
	return 0;
}
