//Operator Overloading Real and Imaginary
#include<iostream>
using namespace std;

class Numbers
{
	public:
		
	Numbers(int x , int y)
	{
		
		real = x;
		imag = y;
		
	}
	
	
	Numbers operator+(Numbers &obj)
	{
		Numbers temp(0,0);
		
		temp.real = this->real + obj.real;
		temp.imag = this->imag + obj.imag;
		
		return temp;
	}
	
	
		Numbers operator-(Numbers &obj)
	{
		Numbers temp(0,0);
		
		temp.real = this->real - obj.real;
		temp.imag = this->imag - obj.imag;
		
		return temp;
	}
	
	
	
	void print ()
	{
		cout<<"Real "<<real<<" Imaginary"<<imag;
	}
	
	private:
		int real,imag;
};

int main()
{
	Numbers S1(5,2),S2(3,7),S3(10,20);
	
	
	S1=S1+S2+S3;
	S1.print();
	
	S2= S2-S3;
	S2.print();
	return 0;
}
