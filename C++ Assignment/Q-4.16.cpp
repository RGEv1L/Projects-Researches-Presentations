/*  Q-4.16

Develop a C++ program that uses a while statement to determine the
gross pay for each of several employees. The company pays “straight time” for the first 40 hours
worked by each employee and pays “time-and-a-half” for all hours worked in excess of 40 hours.
You are given a list of the employees of the company, the number of hours each employee worked
last week and the hourly rate of each employee. Your program should input this information for
each employee and should determine and display the employee’s gross pay
*/

#include<iostream>
using namespace std;

int main()
{
int H_Rate,H_Worked,Salary;

	cout<<"Welcome to Salary Calculator\n";
	
while (H_Worked != -1)
{
	cout<<"Enter Hours worked (-1 to end):";
	cin>>H_Worked;
	
		if(H_Worked == -1)       //Instat loop Break
		break;
		
	cout<<"Enter hourly rate of the employee ($00.00):";
	cin>>H_Rate;
	
if(H_Worked > 40)              //Regular + Over Time calculator
	Salary = 40 * H_Rate + (H_Worked - 40) * H_Rate * 1.5;

else                           // Regular Calculator
	Salary = H_Worked * H_Rate;         
	
cout<<"Salary is:"<<Salary<<endl;	

		
}
	
	return 0;
}
