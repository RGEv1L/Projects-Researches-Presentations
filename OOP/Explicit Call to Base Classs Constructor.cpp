#include<iostream>
using namespace std;

class Base
{	
public:
	Base(int x)
	{
		a = x;	
	}	
	
	int geta()
	{
		return a;
		
	}
private:
	int a;	
	
};


class Derived : public Base
{
public:
	Derived(int b , int c) //: Base(c)
	{
		w = b;
		
	}	
	int getw()
	{
		return w;
		
	}
private:
	int w;	
	
	
};

int main()
{
	Derived D(10 , 2);
	
	cout<<D.getw()<<"\n"<<D.geta();
	
	return 0;
}
