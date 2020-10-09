#include<iostream>
using namespace std;


class B; //declaration of class B is requried for compilation of friend class inside the class A
class A
{
friend class B;		

private:
	int y;	
	
};

class B
{

public:	
 void set(A &a ) // passing the object of class A in class B to access the private varibles of A
		{
			a.y = 10;
			cout<<a.y;
		}

private:
	int z;	
	
};



int main()
{
	A a;
	B b;
	b.set(a);	//passing object of A in B to acces A inside B
	
	
	return 0;
}
