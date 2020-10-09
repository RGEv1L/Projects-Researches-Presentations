#include<iostream>
using namespace std;

class A
{
public:
	int x,y,z;
	
	
	
};

int main()
{
	A a,b;
	
	a.x=10;
	a.y=15;
	a.z=20;
	
	//Transfering data stored in objec a  in b via default membervise assignment operator(=)
	b=a;
	
	cout<<b.x<<b.y<<b.z;
	
	
	
	return 0;
}
