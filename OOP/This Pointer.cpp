//Every object in C++ has access to its own address through an important pointer called this pointer.
// The this pointer is an implicit parameter to all member functions.
// Therefore, inside a member function, this may be used to refer to the invoking object.
#include<iostream>
using namespace std;


class A
{
public:	
//variables in definition are same as declared in class
//so this-> is used to retrieve the address of current object of class A 
	A(int x ,int y,int z) 	
	{
		
		this->x = x;
		this->y = y;
		this->z = z;
		
	}
//Here This-> is just being used to show that this-> means the current object's address
	void print()
	{
		cout<<this->x;
		cout<<this->y;
		cout<<this->z;
	}
private:
	int x,y,z;	
	
	
};

int main()
{
	A a(10,20,30);
	a.print();
	
	return 0;
}

