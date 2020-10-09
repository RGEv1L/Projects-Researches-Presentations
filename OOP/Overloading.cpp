#include<iostream>
using namespace std;

class Base
{
public:
	//Overloaded Functions
	void show()
	{
		cout<<"Function with no arguments\n";
	}
	void show(int x)
	{
		cout<<"Function with 1 int argument\n";
	}
	void show(double x)
	{
		cout<<"Function with 1 float argument\n";
	}
	void show(int x,float y)
	{
		cout<<"Function with 1 int and 1 float argument\n";
	}
	void show(float x,int y)
	{
		cout<<"Function with 1 float and 1 int argument\n";
	}
	
	//Error generated because in overloading ,return type doesnt matter
	/*int show(float x,int y)
	{
		cout<<"Function with 1 float and 1 int argument\n";
	}
	*/
};

int main()
{
	Base A;
	//Overloaded Functions Calling
	A.show();
	A.show(2);
	A.show(1.999);
	A.show(2,1.1);
	A.show(1.1,2);
	
	
	return 0;
}
