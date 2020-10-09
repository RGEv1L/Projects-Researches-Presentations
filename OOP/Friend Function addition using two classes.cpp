#include<iostream>
using namespace std;


class B;
class A
{
	
friend void set(A & , B &); //Only Prototype is provided inside the class
		


private:
	int y;	
	
};

class B
{
	
friend void set(A & , B &); //Same prototype is provided as in Class A
		


private:
	int z;	
	
};

void set(A &a , B &b)	//Functuin Declaration
{
	
	a.y = 10;
	b.z = 20;
	cout<<a.y+b.z;
	
}

int main()
{
	A a;
	B b;
	set(a,b);
	
	
	return 0;
}
