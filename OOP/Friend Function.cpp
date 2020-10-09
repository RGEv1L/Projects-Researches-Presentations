#include<iostream>
using namespace std;

class A
{
	
friend void set(A &); //Only Prototype is provided inside the class
		

public:
	int w;
	
	
protected:
	int x;	
	
private:
	int y;	
	
};

void set(A &b)	//Functuin Declaration
{
	b.w = 10;
	b.x = 20;
	b.y = 30;
	
	cout<<b.w<<b.x<<b.y;
	
}

int main()
{
	A a;
	set(a);
	cout<<a.w;
	
	
	return 0;
}
