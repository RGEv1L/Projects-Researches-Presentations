#include<iostream>
using namespace std;

class A
{
public:
	
 void print() const
 {	
 	 x= 10;  error! assignment of member 'A::x' in read-only object
	 cout<<x;
 }	



private:
	int x;	
	
};

int main()
{
	A a;
	a.print();
	
	
	return 0;
}
