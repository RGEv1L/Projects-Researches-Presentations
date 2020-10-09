#include <iostream>
using namespace std;

// Abstract class
//For a virtual function you need to provide implementation in the base class. 
//However derived class can override this implementation with its own implementation.
// Normally , for pure virtual functions implementation is not provided. 
//You can make a function pure virtual with =0 at the end of function declaration. 
//Also, a class containing a pure virtual function is abstract i.e. you can not create a object of this class.
class Shape                   
{
    protected:
       float l;
    public:
       void getData()       
       {
           cin >> l;
       }
       
       // virtual Function
       virtual float calculateArea() = 0; //no definition
};

class Square : public Shape
{
    public:
       float calculateArea()
       {   return l*l;  }
};

class Circle : public Shape
{
    public:
       float calculateArea()
       { return 3.14*l*l; }
};

int main()
{	//you cant declare object of base class as it is an abstract class containig pure virtual function
    Square s;
    Circle c;

    cout << "Enter length to calculate the area of a square: ";
    s.getData();
    cout<<"Area of square: " << s.calculateArea();
    cout<<"\nEnter radius to calculate the area of a circle: ";
    c.getData();
    cout << "Area of circle: " << c.calculateArea();

    return 0;
}
