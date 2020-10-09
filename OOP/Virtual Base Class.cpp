#include<iostream>
using namespace std;

class Base
{
public:
	void show()
	{
		cout<<x;
	}
	int x;

};
class D1 : public virtual Base
{

};
class D2 :public virtual Base
{

};

class Derived : public D1,public D2
{


};

int main()
{
	Derived D;
    D.show(); //"error: request for member 'show' is ambiguous:" without virtual base class

	return 0;
}
